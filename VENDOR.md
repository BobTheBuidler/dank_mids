# Vendoring Third-Party Python Libraries

This project vendors select third-party Python libraries directly into the repository. This approach is used to:
- Enable compilation with mypyc for maximum performance
- Ensure compatibility and reproducibility
- Avoid dependency conflicts or breakages from upstream changes
- Allow for patching or customization if needed

## Directory Structure

All vendored libraries are placed under:

```
dank_mids/_vendor/<package_name>/
```

For example, the aiolimiter library is vendored at:

```
dank_mids/_vendor/aiolimiter/
```

## Vendoring Workflow

### 1. Adding a New Vendored Library

To vendor a new library (e.g., `aiolimiter`):

- Use `git subtree` to pull in the upstream repository:

  ```sh
  git subtree add --prefix=dank_mids/_vendor/aiolimiter https://github.com/mjpieters/aiolimiter.git main --squash
  ```

  - Replace `aiolimiter` and the repo URL with the appropriate package and upstream repository.
  - The `--squash` flag creates a single commit for the import.

- If you only want a subdirectory (e.g., the package code, not tests/docs), you may need to remove unnecessary files after import.

### 2. Updating a Vendored Library

To update a vendored library to the latest upstream version:

- Use the Makefile target (if available), or run:

  ```sh
  git subtree pull --prefix=dank_mids/_vendor/aiolimiter https://github.com/mjpieters/aiolimiter.git main --squash
  ```

  - Adjust the path and repo URL as needed for other libraries.

- Review the changes, resolve any conflicts, and test your code.

### 3. Makefile Integration

For each vendored library, add a Makefile target to update it. Example for aiolimiter:

```makefile
update-aiolimiter:
	git subtree pull --prefix=dank_mids/_vendor/aiolimiter https://github.com/mjpieters/aiolimiter.git main --squash
```

For additional libraries, add similar targets.

### 4. Compiling with mypyc

- Add the relevant `.py` files from each vendored library to your `mypyc` command in the Makefile.
- Example:

  ```makefile
  mypyc:
  	mypyc ... dank_mids/_vendor/aiolimiter/__init__.py dank_mids/_vendor/aiolimiter/aiolimiter.py ...
  ```

- Update the list if new files are added upstream.

### 5. Using Vendored Libraries

- Import from the vendored path, e.g.:

  ```python
  from dank_mids._vendor.aiolimiter import AsyncLimiter
  ```

- Remove the library from your external dependencies (e.g., Poetry, requirements.txt) to avoid conflicts.

### 6. Patching Vendored Libraries

- If you need to patch a vendored library, make your changes as separate commits after the subtree import.
- Document any patches in this file or in commit messages.
- When updating, re-apply or rebase your patches as needed.

## Best Practices

- Only vendor libraries that are critical for performance, compatibility, or stability.
- Keep vendored code up to date with upstream to receive bug fixes and improvements.
- Minimize patches to vendored code; prefer upstream contributions when possible.
- Always test thoroughly after updating or patching vendored libraries.

## Example: aiolimiter

- Vendored at: `dank_mids/_vendor/aiolimiter/`
- Upstream: https://github.com/mjpieters/aiolimiter
- Update with: `make update-aiolimiter`
- Compile with mypyc: add files to Makefile as shown above

---

This workflow ensures that vendored libraries are easy to add, update, and maintain, while maximizing performance and minimizing dependency issues.
