.PHONY: docs

mypy:
	mypy ./dank_mids --pretty --ignore-missing-imports --show-error-codes --show-error-context --no-warn-no-return

docs:
	rm -r ./docs/source -f
	rm -r ./docs/_templates -f
	rm -r ./docs/_build -f
	poetry run sphinx-apidoc -o ./docs/source ./dank_mids

mypyc:
	mypyc dank_mids/_eth_utils.py --strict --pretty --disable-error-code unused-ignore
	mypyc dank_mids/_uid.py --strict --pretty
	mypyc dank_mids/brownie_patch/__init__.py --strict --pretty
	mypyc dank_mids/brownie_patch/_abi.py --strict --pretty
	mypyc dank_mids/brownie_patch/call.py --pretty
	mypyc dank_mids/brownie_patch/overloaded.py --strict --pretty
	mypyc dank_mids/brownie_patch/types.py --strict --pretty
	mypyc dank_mids/helpers/_weaklist.py --strict --pretty
	mypyc dank_mids/helpers/lru_cache.py --strict --pretty

mypyc-3-8:
	mypyc dank_mids/_eth_utils.py --strict --pretty --disable-error-code unused-ignore
	mypyc dank_mids/_uid.py --strict --pretty
	mypyc dank_mids/brownie_patch/__init__.py --strict --pretty
	mypyc dank_mids/brownie_patch/_abi.py --strict --pretty
	mypyc dank_mids/brownie_patch/call.py --pretty
	mypyc dank_mids/brownie_patch/overloaded.py --strict --pretty
	mypyc dank_mids/brownie_patch/types.py --strict --pretty
