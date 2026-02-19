# Testing

## Quick Start
- `make test-unit`
- `make test-unit-mypyc`
These assume your dev venv is active (or `pytest` is on `PATH`). If not, run
`PYTEST_DISABLE_PLUGIN_AUTOLOAD=1 ./.venv/bin/python -m pytest tests/unit`, or
`PYTHON=./.venv/bin/python make test-unit`.
Make sure the package is installed in your venv (`pip install -e .` or `poetry install`).

## Why The Build Venv Exists
CI compiles with only `requirements-build.txt`. If your local dev env has extra deps
(e.g. `web3` or `eth-brownie`), mypyc can see their type hints and fail locally
even though CI passes. `make test-unit-mypyc` compiles in an isolated build venv
(`env/mypyc`) so local behavior matches CI.

## Commands
- `make mypyc`: compile using the current env (matches CI only if your env mirrors `requirements-build.txt`).
- `make mypyc-venv`: compile using the isolated build venv and `requirements-build.txt`.
- `make test-unit`: run unit tests (pure Python).
- `make test-unit-mypyc`: compile with `mypyc-venv`, then run unit tests with compiled modules required.

## Environment Variables
- `DANK_MIDS_REQUIRE_COMPILED=1`: fail if compiled extensions are not loaded.
- `PYTEST_DISABLE_PLUGIN_AUTOLOAD=1`: keep external pytest plugins from interfering.

## Build Venv Controls
- Override the venv path: `MYPYC_VENV=/path/to/venv make mypyc-venv`
- Choose the Python used to create the venv: `MYPYC_VENV_PYTHON=python3.12 make mypyc-venv`
- Use the same Python version for build and test; compiled modules are version-specific.

## Cleaning
- Delete `env/mypyc` if you need to rebuild the build venv from scratch.
- Mypyc builds generate artifacts under `build/` and `*.so`/`*.pyd` files; do not
  commit them unless explicitly requested.
