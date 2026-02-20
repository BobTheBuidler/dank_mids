# Contributing

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
