from setuptools import setup
from mypyc.build import mypycify

setup(name='mypyc_output',
      ext_modules=mypycify(['dank_mids/helpers/lru_cache.py', '--strict', '--pretty'], opt_level="3", debug_level="1", strict_dunder_typing=True),
)
