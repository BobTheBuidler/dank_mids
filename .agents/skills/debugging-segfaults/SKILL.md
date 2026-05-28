---
name: debugging-segfaults
description: Trace Python native-extension segfaults in this repo, especially mypyc crashes during compiled imports, CI-only failures, or extension/source import mismatches.
---

# Debugging Segfaults

Use this workflow when Python exits with `Segmentation fault`, `Fatal Python error`, or a native mypyc extension crashes during import or tests.

## Workflow

1. Reproduce outside the working tree first.
   - Create a temp checkout from the target commit and copy submodule contents if the archive does not include them.
   - Point `PYTHONPATH` or `cwd` at the temp checkout, but reuse the repo venv only if dependency state is already known.
   - Set `PYTHONFAULTHANDLER=1` and any repo noise suppressors such as `TYPEDENVS_SHUTUP=1`.

2. Build the compiled surface exactly like CI.
   - Prefer `scripts/ci/build_source_extensions.py --artifact-dir <tmp-artifacts>` for source-tree mypyc builds.
   - Leave generated `.so`/`.pyd` files and build directories out of commits unless the user explicitly asks for binaries.

3. Reduce the crash to the smallest import or test.
   - Start with the parameterized compiled import test, then try direct imports with `python -c`.
   - Import candidate modules one at a time until one import reliably crashes.
   - Compare source mode by moving temp native extensions aside instead of editing tracked files.

4. Capture a native backtrace.
   - Run the minimal reproducer under `gdb --batch` with `run` and `bt`.
   - Look for the first repo or mypyc runtime frame, not only the Python faulthandler stack.
   - For import crashes, inspect compiled package `__init__` files and mypyc runtime setup frames such as `CPyImport_SetDunderAttrs`.

5. Treat `sys.modules` carefully.
   - Do not delete and reimport already-loaded mypyc native modules in the same interpreter.
   - Mypyc extensions may keep C-level static module state that is not reset by removing Python entries from `sys.modules`.
   - Tests that source-load or stub repo modules must restore prior module state after each test.

6. Classify every interacting cause.
   - Separate the real crash trigger from test harness leaks, CI exposure, and unrelated timeouts.
   - Verify each fix against the direct crash reproducer, the focused test, and the full relevant compiled suite.

## Reporting

Report the exact target commit, Python version, mypy/mypyc version, build command, smallest crashing import or test parameter, native backtrace root frame, and which behavior is pre-existing versus newly introduced by the branch.
