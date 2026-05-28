.PHONY: docs mypy mypyc pytest test test-clean

PYTHON ?= uv run python
PYTEST_CMD ?= PYTEST_DISABLE_PLUGIN_AUTOLOAD=1 uv run pytest

mypy:
	uv run --only-group mypy mypy

docs:
	rm -r ./docs/source -f
	rm -r ./docs/_templates -f
	rm -r ./docs/_build -f
	uv run --group docs sphinx-apidoc -o ./docs/source ./dank_mids

benchmark:
	uv run brownie run examples/benchmark

mypyc:
	uv run --only-group build python scripts/run_mypyc_build.py

pytest:
	$(PYTEST_CMD)

test:
	@set -e; \
	trap '$(MAKE) --no-print-directory test-clean' EXIT; \
	$(MAKE) --no-print-directory mypyc; \
	$(MAKE) --no-print-directory pytest

test-clean:
	git submodule update --init --recursive --checkout --force dank_mids/_vendor/aiolimiter ||:
	git ls-files -z -- 'dank_mids/**/*.so' 'dank_mids/**/*.pyd' 'build/**/*.c' 'build/**/*.h' \
		| xargs -0r git restore --source=HEAD --worktree --staged -- ||:
	git clean -fd -- build ||:
	find dank_mids -type f \( -name '*.so' -o -name '*.pyd' \) ! -path 'dank_mids/_vendor/*' -print0 \
		| xargs -0r sh -c 'for f do git ls-files --error-unmatch "$$f" >/dev/null 2>&1 || rm -f "$$f"; done' _ ||:
	git clean -f -- '*__mypyc*.so' '*__mypyc*.pyd' ||:


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
