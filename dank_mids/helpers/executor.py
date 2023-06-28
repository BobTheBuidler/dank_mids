import queue
import threading
import weakref
from concurrent.futures import ThreadPoolExecutor, _base, thread

TEN_MINUTES = 60 * 10

def _worker(executor_reference, work_queue, initializer, initargs, timeout):  # NOTE: NEW 'timeout'
    if initializer is not None:
        try:
            initializer(*initargs)
        except BaseException:
            _base.LOGGER.critical('Exception in initializer:', exc_info=True)
            executor = executor_reference()
            if executor is not None:
                executor._initializer_failed()
            return
        
    try:
        while True:
            try:  # NOTE: NEW
                work_item = work_queue.get(block=True, 
                                           timeout=timeout)  # NOTE: NEW
            except queue.Empty:  # NOTE: NEW
                # Its been 'timeout' seconds and there are no new work items.  # NOTE: NEW
                # Let's suicide the thread.  # NOTE: NEW
                executor = executor_reference()  # NOTE: NEW
                
                with executor._adjusting_lock:  # NOTE: NEW
                    # NOTE: We keep a minimum of one thread active to prevent locks
                    if len(executor) > 1:  # NOTE: NEW
                        t = threading.current_thread()  # NOTE: NEW
                        executor._threads.remove(t)  # NOTE: NEW
                        thread._threads_queues.pop(t)  # NOTE: NEW
                        # Let the executor know we have one less idle thread available
                        executor._idle_semaphore.acquire(blocking=False)  # NOTE: NEW
                        return  # NOTE: NEW 
                continue
                
            if work_item is not None:
                work_item.run()
                # Delete references to object. See issue16284
                del work_item

                # attempt to increment idle count
                executor = executor_reference()
                if executor is not None:
                    executor._idle_semaphore.release()
                del executor
                continue

            executor = executor_reference()
            # Exit if:
            #   - The interpreter is shutting down OR
            #   - The executor that owns the worker has been collected OR
            #   - The executor that owns the worker has been shutdown OR
            if thread._shutdown or executor is None or executor._shutdown:
                # Flag the executor as shutting down as early as possible if it
                # is not gc-ed yet.
                if executor is not None:
                    executor._shutdown = True
                # Notice other workers
                work_queue.put(None)
                return
            del executor
    except BaseException:
        _base.LOGGER.critical('Exception in worker', exc_info=True)

class PruningThreadPoolExecutor(ThreadPoolExecutor):
    """
    This ThreadPoolExecutor implementation prunes inactive threads after 'timeout' seconds without a work item.
    Pruned threads will be automatically recreated as needed for future workloads. up to 'max_threads' can be active at any one time.
    """
    def __init__(self, max_workers=None, thread_name_prefix='',
                 initializer=None, initargs=(), timeout=TEN_MINUTES):
        self._timeout=timeout
        self._adjusting_lock = threading.Lock()
        super().__init__(max_workers, thread_name_prefix, initializer, initargs)
    
    def __repr__(self) -> str:
        return f"<dank_mids.{self.__class__.__name__} object at {hex(id(self))} [{len(self)} threads]>"
    
    def __len__(self) -> int:
        return len(self._threads)
        
    def _adjust_thread_count(self):
        with self._adjusting_lock:
            # if idle threads are available, don't spin new threads
            if self._idle_semaphore.acquire(timeout=0):
                return

            # When the executor gets lost, the weakref callback will wake up
            # the worker threads.
            def weakref_cb(_, q=self._work_queue):
                q.put(None)

            num_threads = len(self._threads)
            if num_threads < self._max_workers:
                thread_name = '%s_%d' % (self._thread_name_prefix or self,
                                         num_threads)
                t = threading.Thread(name=thread_name, target=_worker,
                                     args=(weakref.ref(self, weakref_cb),
                                           self._work_queue,
                                           self._initializer,
                                           self._initargs,
                                           self._timeout))
                t.daemon = True
                t.start()
                self._threads.add(t)
                thread._threads_queues[t] = self._work_queue

executor = PruningThreadPoolExecutor(128)
