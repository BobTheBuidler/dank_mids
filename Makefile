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

mypyc: mypyc-eth-utils mypyc-uid mypyc-brownie-patch
	mypyc dank_mids/helpers/_codec.py --strict --pretty --disable-error-code unused-ignore
	mypyc dank_mids/helpers/_weaklist.py --strict --pretty
	mypyc dank_mids/helpers/lru_cache.py --strict --pretty

mypyc-3-8: mypyc-eth-utils mypyc-uid mypyc-brownie-patch
	mypyc dank_mids/helpers/_codec.py --strict --pretty --disable-error-code unused-ignore

mypyc-eth-utils:
	mypyc dank_mids/_eth_utils.py --strict --pretty --disable-error-code unused-ignore

mypyc-uid:
	mypyc dank_mids/_uid.py --strict --pretty

mypyc-brownie-patch:
	mypyc dank_mids/brownie_patch/__init__.py dank_mids/brownie_patch/_abi.py dank_mids/brownie_patch/call.py dank_mids/brownie_patch/overloaded.py dank_mids/brownie_patch/types.py --strict --pretty --disable-error-code unused-ignore