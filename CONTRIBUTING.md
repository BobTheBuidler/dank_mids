# Contributing

## Compiled Runtime Contract

dank-mids is validated as a compiled mypyc package. Treat tracked `.py` files as
mypyc source inputs for the compiled runtime, not as a separate supported direct
`.py` execution path.

CI validates compiled source-tree artifacts copied into the checkout, and
release tests validate compiled wheel artifacts imported from the installed
wheel. Terms such as `source-tree` describe where native `.so`/`.pyd` artifacts
are imported from; they do not imply direct `.py` execution.

## Pre-commit

This repository uses `pre-commit` for local checks before commit.

### Install

Use one of the following:

```bash
pipx install pre-commit
```

```bash
python -m pip install pre-commit
```

### Setup

Run this once after cloning:

```bash
pre-commit install
```

### Daily usage

Run checks on changed files:

```bash
pre-commit run
```

Run checks for all tracked files:

```bash
pre-commit run --all-files
```

Run only YAML validation:

```bash
pre-commit run check-yaml --all-files
```

### Updating hooks

To update hook revisions:

```bash
pre-commit autoupdate
```

### Notes

`check-yaml` runs in strict mode in this repo. YAML files with custom tags may fail validation unless explicitly handled in a future config update.
