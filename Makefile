.PHONY: docs mypy mypyc mypyc-deps

PYTHON ?= python
MYPYC_DEPS = mypy[mypyc]==1.19.1 \
	setuptools \
	types-requests \
	eth-typing==5.2.1 \
	eth-retry==0.3.5 \
	ez-a-sync==0.33.9 \
	faster-eth-abi==5.2.22 \
	faster-eth-utils==5.3.20 \
	faster-hexbytes==1.3.5 \
	typed-envs==0.2.4

mypy:
	mypy ./dank_mids --pretty --ignore-missing-imports --show-error-codes --show-error-context --no-warn-no-return

docs:
	rm -r ./docs/source -f
	rm -r ./docs/_templates -f
	rm -r ./docs/_build -f
	poetry run sphinx-apidoc -o ./docs/source ./dank_mids

benchmark:
	poetry run brownie run examples/benchmark

mypyc-deps:
	$(PYTHON) -m pip install $(MYPYC_DEPS)

mypyc: mypyc-deps
	MYPYC_STRICT_DUNDER_TYPING=1 mypyc dank_mids/_batch.py \
		dank_mids/_demo_mode.py \
		dank_mids/_envs.py \
		dank_mids/_eth_utils.py \
		dank_mids/_exceptions.py \
		dank_mids/_tasks.py \
		dank_mids/_uid.py \
		dank_mids/_vendor/aiolimiter/src \
		dank_mids/_web3/abi.py \
		dank_mids/_web3/formatters.py \
		dank_mids/brownie_patch/__init__.py \
		dank_mids/brownie_patch/_abi.py \
		dank_mids/brownie_patch/call.py \
		dank_mids/brownie_patch/overloaded.py \
		dank_mids/brownie_patch/types.py \
		dank_mids/constants.py \
		dank_mids/controller.py \
		dank_mids/ENVIRONMENT_VARIABLES.py \
		dank_mids/helpers/__init__.py \
		dank_mids/helpers/_codec.py \
		dank_mids/helpers/_errors.py \
		dank_mids/helpers/_gather.py \
		dank_mids/helpers/_rate_limit.py \
		dank_mids/helpers/_requester.py \
		dank_mids/helpers/_weaklist.py \
		dank_mids/helpers/batch_size.py \
		dank_mids/helpers/hashing.py \
		dank_mids/helpers/lru_cache.py \
		dank_mids/helpers/method.py \
		dank_mids/lock.py \
		dank_mids/logging.py \
		dank_mids/middleware.py \
		dank_mids/stats/__init__.py \
		--strict --pretty --disable-error-code=unused-ignore


# Vendoring

# Robustly set up or update aiolimiter submodule to the latest "mypyc" branch from your fork
update-aiolimiter:
	git submodule update --init --recursive dank_mids/_vendor/aiolimiter || true
	git submodule sync dank_mids/_vendor/aiolimiter || true
	cd dank_mids/_vendor/aiolimiter && \
		git remote set-url origin https://github.com/BobTheBuidler/aiolimiter.git && \
		git fetch origin mypyc && \
		git checkout mypyc && \
		git pull origin mypyc

# Update the TaskStart hook submodule and commit the change
hooks:
	mkdir -p .clinerules/hooks/submodules
	# TaskStart hook update
	if [ ! -d .clinerules/hooks/submodules/TaskStart ]; then 		git submodule add https://github.com/BobTheBuidler/TaskStart.git .clinerules/hooks/submodules/TaskStart || true; 		git add .gitmodules .clinerules/hooks/submodules/TaskStart; 	fi
	git submodule update --init --recursive
	git -c protocol.file.allow=always submodule update --remote .clinerules/hooks/submodules/TaskStart
	cp .clinerules/hooks/submodules/TaskStart/TaskStart .clinerules/hooks/TaskStart
	git add .clinerules/hooks/submodules/TaskStart
	git add .clinerules/hooks/TaskStart
	if ! git diff --cached --quiet; then 		git commit -m "Update TaskStart hook submodule and file"; 	fi
	# PostToolUse hook update
	if [ ! -d .clinerules/hooks/submodules/PostToolUse ]; then 		git submodule add https://github.com/BobTheBuidler/PostToolUse.git .clinerules/hooks/submodules/PostToolUse || true; 		git add .gitmodules .clinerules/hooks/submodules/PostToolUse; 	fi
	git submodule update --init --recursive
	git -c protocol.file.allow=always submodule update --remote .clinerules/hooks/submodules/PostToolUse
	cp .clinerules/hooks/submodules/PostToolUse/PostToolUse .clinerules/hooks/PostToolUse
	chmod +x .clinerules/hooks/PostToolUse
	git add .clinerules/hooks/submodules/PostToolUse
	git add .clinerules/hooks/PostToolUse
	if ! git diff --cached --quiet; then 		git commit -m "Update PostToolUse hook submodule and file"; 	fi
