# Agent Requirements

All agents must follow these rules:

1) Fully test your changes before submitting a PR (run the full suite or all relevant tests).
2) PR titles must be descriptive and follow Conventional Commits-style prefixes:
   - Common: `feat:`, `fix:`, `chore:`, `refactor:`, `docs:`, `test:`, `perf:`
   - Support titles: `fix(docs):`, `fix(benchmarks):`, `fix(cicd):`
3) Commit messages must follow the same Conventional Commits-style prefixes and include a short functional description plus a user-facing value proposition.
4) PR descriptions must include Summary, Rationale, and Details sections.

Reference: https://www.conventionalcommits.org/en/v1.0.0/

## Condition: repo contains Python files
Rules:
- Run relevant Python tests for changes (pytest/unittest or the repo's configured runner).
- Follow formatting/linting configured in pyproject.toml, setup.cfg, tox.ini, or ruff.toml.
- Update dependency lockfiles when adding or removing Python dependencies.
