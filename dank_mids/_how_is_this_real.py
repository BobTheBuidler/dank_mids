
import logging
from logging.handlers import RotatingFileHandler

LOGS_PATH = 'just-leave-me-here-and-dont-touch-me-plz.log'
ONE_KB = 1024

silencer = RotatingFileHandler(LOGS_PATH, maxBytes=500*ONE_KB, backupCount=1)

def _the_most_absurd_fix_youve_ever_seen():
    """
    Somehow this resolves a race condition enough for the library to work as intended.
    How? I have no idea at all. Please don't ask me, its magic.
    I'll debug this later once I've pooshed a stable release to prod.
    """
    enable_logger_but_divert_stream('a_sync.abstract')
    enable_logger_but_divert_stream('a_sync.base')
    enable_logger_but_divert_stream('dank_mids.controller')
    enable_logger_but_divert_stream('dank_mids.session')
    enable_logger_but_divert_stream('dank_mids.semaphores')

def enable_logger_but_divert_stream(name, show_every_x=None):
    logger = logging.getLogger(name)
    if logging.root.isEnabledFor(logging.DEBUG) or logger.isEnabledFor(logging.DEBUG):
        # We don't need to do anything, the user has indicated they want the debug logs enabled and shown
        return
    # Break the logger apart from the root logger and its handlers
    logger.propagate = False
    # Enable the logger regardless of root settings
    logger.setLevel(logging.DEBUG)
    # remove the root handler that was added at basicConfig step (not sure if this is actually necessary)
    logger.removeHandler(logging.StreamHandler())
    # ensure the logger has no handlers
    assert logger.handlers == [], logger.handlers
    # add the silencer handler to direct the logs to a throwaway file
    logger.addHandler(silencer)
    
