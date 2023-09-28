
import logging
from datetime import datetime
from typing import Optional

import a_sync

from dank_mids.helpers import decode
from dank_mids.types import BytesStream, StreamedJSONArrayOfObjects, StreamedJSONObject

END_OF_ARRAY = b']\n'

logger = logging.getLogger(__name__)

class EndOfStreamError(Exception):
    pass

async def of_objects(stream: BytesStream) -> StreamedJSONArrayOfObjects:
    done = 0
    chunk_num = 0
    started_at = datetime.now()
    proceed_to_next = a_sync.Event()
    
    working = await stream.__anext__()
    if working[0:1] == b'{':
        # This means we received an err response from the rpc
        # NOTE: We assume such a small response was fully received, this assumption may turn out to be incorrect
        # NOTE: This probably belongs somewhere else so the `of_objects` function can be used in a more generalized manner.
        raise decode.partial(working).exception
    elif not working.startswith(b'['):
        raise NotImplementedError(working)
    
    async def stream_next_object() -> StreamedJSONObject:
        logger.debug('starting json object stream generator')
        nonlocal working, chunk_num
        sent = 0
        while True:
            if working == END_OF_ARRAY:
                raise EndOfStreamError('end of response reached')
            start = _find_object_start(working)
            end = _find_object_end(working, start)
            if end:
                yield working[start+sent:end]
                working = working[end:]
                proceed_to_next.set()
                logger.debug('exiting json object stream generator')
                return
            to_send = working[start+sent:]
            yield to_send
            sent += len(to_send)
            if chunk_num > 0:
                st = f'chunk {chunk_num}  {done} completed  {datetime.now() - started_at}'
                logger.info(st)
                print(st)
            chunk_num += 1
            working += await stream.__anext__()
             
    while working != END_OF_ARRAY:
        next_object_generator = stream_next_object()
        logger.debug('yielding next object generator')
        yield next_object_generator
        await proceed_to_next.wait()
        done += 1
        proceed_to_next.clear()
    logger.debug('stream done')
    
def _find_object_start(b: bytes) -> int:
    start = b.find(b'{')
    assert start in [0, 1], f'expected 0 or 1, got {start}  bytes: {b}'
    if not start == 1:
        print(f"object start: {start}")
    return start

def _find_object_end(b: bytes, object_start: int) -> Optional[int]:
    i = object_start
    counter = 1
    while counter:
        next_obj = b.find(b'{', i+1)
        next_end = b.find(b'}', i+1)
        if next_end == -1:
            return None
        elif next_obj == -1:
            i = next_end
            counter -= 1
        elif next_end < next_obj:
            i = next_end
            counter -= 1
        else:
            i = next_obj
            counter += 1
    object_end = next_end + 1
    assert b[object_end:object_end+1] in [b'', b',', b']'], f"expected one of: b'', b',', b']'  got: {b[object_end:object_end+1]}"
    return object_end