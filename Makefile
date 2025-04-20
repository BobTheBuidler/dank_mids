.PHONY: docs

mypy:
	mypy ./dank_mids --pretty --ignore-missing-imports --show-error-codes --show-error-context --no-warn-no-return

docs:
	rm -r ./docs/source -f
	rm -r ./docs/_templates -f
	rm -r ./docs/_build -f
	poetry run sphinx-apidoc -o ./docs/source ./dank_mids

mypyc:
	mypyc dank_mids/_uid.py
	mypyc dank_mids/brownie_patch/__init__.py
	mypyc dank_mids/brownie_patch/_abi.py
	mypyc dank_mids/brownie_patch/call.py
	mypyc dank_mids/brownie_patch/overloaded.py
	mypyc dank_mids/brownie_patch/types.py
	mypyc dank_mids/helpers/_weaklist.py
