# Agent Requirements

All agents must follow these rules:

1) Sandbox runs may block Unix socketpair wakeups; rerun asyncio/threaded failures outside the sandbox before declaring repo, mypyc, or Python regressions.
2) Fully test your changes before submitting a PR (run the full suite or all relevant tests): `PYTEST_DISABLE_PLUGIN_AUTOLOAD=1 pytest <files>`
3) PR titles must be descriptive and follow Conventional Commits-style prefixes:
   - Common: `feat:`, `fix:`, `chore:`, `refactor:`, `docs:`, `test:`, `perf:`
   - Support titles: `fix(docs):`, `fix(benchmarks):`, `fix(cicd):`
4) Commit messages must follow the same Conventional Commits-style prefixes and include a short functional description plus a user-facing value proposition.
5) PR descriptions must include Summary, Rationale, and Details sections.
6) Run relevant Python tests for changes (pytest/unittest or the repo's configured runner).
7) All new or edited code must have 90%+ coverage in tests/unit full suite.
8) Follow formatting/linting configured in pyproject.toml, setup.cfg, tox.ini, or ruff.toml.
9) Update dependency lockfiles when adding or removing Python dependencies.
10) If the repo uses mypyc, verify tests run against compiled extensions (not interpreted Python) and note how you confirmed.
11) Maximize the use of caching in GitHub workflow files to minimize run duration.
12) Use one of `paths` or `paths-ignore` in every workflow file to make sure workflows only run when required.
13) All mypy configuration (flags, overrides, per-module ignores, and file targets) should go in pyproject.toml. Do not split config across CLI args, mypy.ini, setup.cfg, or workflow steps.
14) Centralize pytest settings (flags, markers, ignore patterns, and targets) in pyproject.toml, pytest.ini, setup.cfg, or tox.ini; workflows/hooks should call pytest without inline args.
15) If the branch you're assigned to work on is from a remote (ie origin/master or upstream/awesome-feature) you must ensure you fetch and pull from the remote before you begin your work.

## Repo Behavior Notes
- `WeakList` uses weakrefs on purpose to avoid keeping abandoned calls alive; empty batches or empty JSON-RPC posts can happen when all queued calls are GC'd or drained, and that is expected. Don't "fix" this by switching to strong refs unless we explicitly change the design.
- Generated C/H artifacts (`build/**/*.c`, `build/**/*.h`) are versioned for mypyc diff review; keep binary extensions (`.pyd`, `.so`) out of PRs.
- `dank_mids/_vendor/aiolimiter` is a pinned submodule; update its pointer only when explicitly requested.

Reference: https://www.conventionalcommits.org/en/v1.0.0/
