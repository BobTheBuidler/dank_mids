from setuptools import setup
from mypyc.build import mypycify

setup(name='mypyc_output',
      ext_modules=mypycify(['dank_mids/_batch.py', 'dank_mids/_demo_mode.py', 'dank_mids/_envs.py', 'dank_mids/_eth_utils.py', 'dank_mids/_exceptions.py', 'dank_mids/_logging.py', 'dank_mids/_uid.py', 'dank_mids/brownie_patch/__init__.py', 'dank_mids/brownie_patch/_abi.py', 'dank_mids/brownie_patch/call.py', 'dank_mids/brownie_patch/overloaded.py', 'dank_mids/brownie_patch/types.py', 'dank_mids/helpers/_codec.py', 'dank_mids/helpers/_errors.py', 'dank_mids/helpers/_gather.py', 'dank_mids/helpers/lru_cache.py', 'dank_mids/helpers/_weaklist.py', 'dank_mids/constants.py', 'dank_mids/ENVIRONMENT_VARIABLES.py', '--strict', '--pretty', '--disable-error-code', 'unused-ignore', '--disable-error-code', 'has-type'], opt_level="3", debug_level="1", strict_dunder_typing=True),
)
