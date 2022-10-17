import logging

from lazy_logging import LazyLoggerFactory

main_logger = logging.getLogger("dank_mids")
demo_logger = logging.getLogger("dank_mids.demo_mode")
sort_logger = logging.getLogger("dank_mids.should_batch")

sort_lazy_logger = LazyLoggerFactory("DANKMIDS_SHOULDBATCH")(sort_logger)
