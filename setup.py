from pathlib import Path
from setuptools import find_packages, setup
from mypyc.build import mypycify


try:
    import tomllib  # Python 3.11+
except ModuleNotFoundError:
    import tomli as tomllib  # Older Python


with Path("pyproject.toml").open("rb") as f:
    pyproject_data = tomllib.load(f)
    poetry_config = pyproject_data["tool"]["poetry"]


def poetry_dependencies_to_install_requires(poetry_deps):
    """
    Reads [tool.poetry.dependencies] in pyproject.toml and converts them
    into a list of valid PEP 508–compatible dependency strings for setuptools.
    """
    if not poetry_deps:
        return []

    install_requires = []
    for name, spec in poetry_deps.items():
        # Poetry often puts a 'python' key for the project's own Python requirement:
        #   [tool.poetry.dependencies]
        #   python = "^3.7"
        # We'll skip that, because it's not an actual package dep.
        if name.lower() == "python":
            continue

        pep508_str = poetry_dep_to_pep508_string(name, spec)
        if pep508_str:
            install_requires.append(pep508_str)

    return install_requires


def poetry_dep_to_pep508_string(package_name, spec):
    """
    Convert a Poetry-style dependency spec into a single string usable by
    setuptools (PEP 508). Handles "version", "markers", "extras", and "python".

    Examples of 'spec':
      ">=1.0"                  (just a string)
      { version=">=1.0,<2.0" }
      { version=">=1.0", markers="python_version < '3.9'", python=">=3.7,<3.10" }
      { extras=["some_extra"], version=">=2.0" }
    """
    if isinstance(spec, str):
        # e.g. ">=1.0" or "*"
        if spec.strip() == "*":
            # "*" means "any version," so just return the package name alone.
            return package_name
        return f"{package_name}{format_version_part(spec)}"

    if isinstance(spec, dict):
        version_part = spec.get("version", "")
        markers_part = spec.get("markers", "")
        python_part = spec.get("python", "")
        extras = spec.get("extras", [])

        # If version == "*", treat it as no version
        if version_part.strip() == "*":
            version_part = ""

        # Turn extras into a "pkg[extra1,extra2]" form if there are any
        if extras:
            pkg_with_extras = f"{package_name}[{','.join(extras)}]"
        else:
            pkg_with_extras = package_name

        # Build up a Python-version marker if "python" is given
        # e.g., python=">=3.7,<3.9" => "python_version >= '3.7' and python_version < '3.9'"
        py_marker = convert_python_spec_to_marker(python_part) if python_part else ""

        # Combine any existing spec markers with this python marker.
        # If both exist, we'll join them with " and ".
        combined_markers = combine_markers(markers_part, py_marker)

        # Build final requirement:
        #   pkg[extras]>1.0 ; (python_version >= '3.7' and <some_other_marker>)
        # If there's no combined_markers, we omit the semicolon part entirely.
        requirement = pkg_with_extras + format_version_part(version_part)
        if combined_markers:
            requirement += f" ; {combined_markers}"

        return requirement

    # If it's unrecognized, just return the package name as a fallback:
    return str(package_name)


def format_version_part(version_spec):
    """
    If version_spec starts with an operator, prepend a space
    so it looks like "mypkg >=1.0.0" instead of "mypkg>=1.0.0".
    """
    if not version_spec:
        return ""
    if version_spec[0] in "<>!~=":
        return f" {version_spec}"
    return f" {version_spec}"


def convert_python_spec_to_marker(python_spec):
    """
    Very basic converter for something like ">=3.7,<3.10"
    into "python_version >= '3.7' and python_version < '3.10'".
    It doesn't handle ^ or ~ operators. If needed, expand this logic.
    """
    if not python_spec:
        return ""

    parts = [p.strip() for p in python_spec.split(",")]
    marker_clauses = []
    for part in parts:
        for op in [">=", "<=", "==", "!=", ">", "<"]:
            if part.startswith(op):
                version_val = part[len(op) :].strip()
                marker_clauses.append(f"python_version {op} '{version_val}'")
                break
        else:
            # If we didn't break, we didn't find a known operator
            # fallback to "=="
            if part:
                marker_clauses.append(f"python_version == '{part}'")

    return " and ".join(marker_clauses)


def combine_markers(a, b):
    """
    Combine two marker expressions (a and b) with "and" if both are non-empty.
    If one is empty, return the other.
    """
    a = a.strip()
    b = b.strip()
    if a and b:
        return f"({a}) and ({b})"
    return a or b

    # Dynamically parse [tool.poetry.dependencies] at runtime and feed into install_requires.

    deps = poetry_config["dependencies"]
    for pkg_name, spec in deps.items():
        if pkg_name.lower() == "python":
            continue


setup(
    name=poetry_config["name"],
    version=poetry_config["version"],
    python_requires=">=3.8,<3.13",
    packages=find_packages(),
    package_data={"evmspec": ["py.typed"]},
    include_package_data=True,
    install_requires=poetry_dependencies_to_install_requires(poetry_config["dependencies"]),
    ext_modules=mypycify(
        [
            "dank_mids/_batch.py",
            "dank_mids/_demo_mode.py",
            "dank_mids/_envs.py",
            "dank_mids/_eth_utils.py",
            "dank_mids/_exceptions.py",
            "dank_mids/_logging.py",
            "dank_mids/_uid.py",
            "dank_mids/_web3/abi.py",
            "dank_mids/_web3/formatters.py",
            "dank_mids/brownie_patch/__init__.py",
            "dank_mids/brownie_patch/_abi.py",
            "dank_mids/brownie_patch/call.py",
            "dank_mids/brownie_patch/overloaded.py",
            "dank_mids/brownie_patch/types.py",
            "dank_mids/helpers/__init__.py",
            "dank_mids/helpers/_codec.py",
            "dank_mids/helpers/_errors.py",
            "dank_mids/helpers/_gather.py",
            "dank_mids/helpers/_weaklist.py",
            "dank_mids/helpers/batch_size.py",
            "dank_mids/helpers/hashing.py",
            "dank_mids/helpers/lru_cache.py",
            "dank_mids/helpers/method.py",
            "dank_mids/stats/__init__.py",
            "dank_mids/constants.py",
            "dank_mids/ENVIRONMENT_VARIABLES.py",
            "--strict",
            "--pretty",
            "--disable-error-code=unused-ignore",
        ]
    ),
    zip_safe=False,
)
