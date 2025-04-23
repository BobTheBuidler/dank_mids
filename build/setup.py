from setuptools import setup
from mypyc.build import mypycify

setup(name='mypyc_output',
      ext_modules=mypycify(['dank_mids/_eth_utils.py', 'dank_mids/_uid.py', 'dank_mids/brownie_patch/__init__.py', 'dank_mids/brownie_patch/_abi.py', 'dank_mids/brownie_patch/call.py', 'dank_mids/brownie_patch/overloaded.py', 'dank_mids/brownie_patch/types.py', 'dank_mids/helpers/_codec.py', 'dank_mids/helpers/lru_cache.py', 'dank_mids/helpers/_weaklist.py', '--strict', '--pretty', '--disable-error-code', 'unused-ignore'], opt_level="3", debug_level="1", strict_dunder_typing=True),
)
