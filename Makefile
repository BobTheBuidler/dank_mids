.PHONY: docs

mypy:
	mypy ./dank_mids --pretty --ignore-missing-imports --show-error-codes --show-error-context --no-warn-no-return

docs:
	rm -r ./docs/source -f
	rm -r ./docs/_templates -f
	rm -r ./docs/_build -f
	poetry run sphinx-apidoc -o ./docs/source ./dank_mids

benchmark:
	poetry run brownie run examples/benchmark

mypyc:
	mypyc dank_mids/_demo_mode.py dank_mids/_eth_utils.py dank_mids/_exceptions.py dank_mids/_uid.py dank_mids/brownie_patch/__init__.py dank_mids/brownie_patch/_abi.py dank_mids/brownie_patch/call.py dank_mids/brownie_patch/overloaded.py dank_mids/brownie_patch/types.py dank_mids/helpers/_codec.py dank_mids/helpers/_errors.py dank_mids/helpers/_gather.py dank_mids/helpers/lru_cache.py dank_mids/helpers/_weaklist.py dank_mids/constants.py dank_mids/ENVIRONMENT_VARIABLES.py --strict --pretty --disable-error-code unused-ignore

mypyc-3-8:
	mypyc dank_mids/_demo_mode.py dank_mids/_eth_utils.py dank_mids/_exceptions.py dank_mids/_uid.py dank_mids/brownie_patch/__init__.py dank_mids/brownie_patch/_abi.py dank_mids/brownie_patch/call.py dank_mids/brownie_patch/overloaded.py dank_mids/brownie_patch/types.py dank_mids/helpers/_codec.py dank_mids/helpers/_errors.py dank_mids/helpers/_gather.py dank_mids/helpers/_weaklist.py dank_mids/constants.py dank_mids/ENVIRONMENT_VARIABLES.py --strict --pretty --disable-error-code unused-ignore

