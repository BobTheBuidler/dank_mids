from __future__ import annotations

import importlib.util
import sys
import zipfile
from pathlib import Path

import pytest

import scripts.ci.mypyc_targets as mypyc_targets
from scripts.ci.mypyc_targets import (
    MYPYC_BUILD_ARGS,
    MYPYC_GROUP_NAME,
    MYPYC_RUNTIME_MODULE,
    MYPYC_SETUP,
    build_dependencies,
    extension_suffix,
    expand_mypyc_targets,
    mypyc_runtime_artifacts,
    mypyc_runtime_force_include,
    preflight_mypyc_build_dependency_surface,
)

MODULE_PATH = Path(__file__).resolve().parents[2] / "scripts" / "run_mypyc_build.py"
CLEAN_EXTENSIONS_PATH = (
    Path(__file__).resolve().parents[2] / "scripts" / "ci" / "clean_source_extensions.py"
)
BUILD_EXTENSIONS_PATH = (
    Path(__file__).resolve().parents[2] / "scripts" / "ci" / "build_source_extensions.py"
)
CHECK_WHEEL_PATH = Path(__file__).resolve().parents[2] / "scripts" / "check_mypyc_wheel.py"
REPO_ROOT = Path(__file__).resolve().parents[2]
SPEC = importlib.util.spec_from_file_location("run_mypyc_build", MODULE_PATH)
assert SPEC is not None and SPEC.loader is not None
run_mypyc_build = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(run_mypyc_build)
CLEAN_EXTENSIONS_SPEC = importlib.util.spec_from_file_location(
    "clean_source_extensions", CLEAN_EXTENSIONS_PATH
)
assert CLEAN_EXTENSIONS_SPEC is not None and CLEAN_EXTENSIONS_SPEC.loader is not None
clean_source_extensions = importlib.util.module_from_spec(CLEAN_EXTENSIONS_SPEC)
CLEAN_EXTENSIONS_SPEC.loader.exec_module(clean_source_extensions)
BUILD_EXTENSIONS_SPEC = importlib.util.spec_from_file_location(
    "build_source_extensions", BUILD_EXTENSIONS_PATH
)
assert BUILD_EXTENSIONS_SPEC is not None and BUILD_EXTENSIONS_SPEC.loader is not None
build_source_extensions = importlib.util.module_from_spec(BUILD_EXTENSIONS_SPEC)
BUILD_EXTENSIONS_SPEC.loader.exec_module(build_source_extensions)
CHECK_WHEEL_SPEC = importlib.util.spec_from_file_location(
    "check_mypyc_wheel", CHECK_WHEEL_PATH
)
assert CHECK_WHEEL_SPEC is not None and CHECK_WHEEL_SPEC.loader is not None
check_mypyc_wheel = importlib.util.module_from_spec(CHECK_WHEEL_SPEC)
CHECK_WHEEL_SPEC.loader.exec_module(check_mypyc_wheel)


def test_build_mypyc_command_contains_targets_and_flags() -> None:
    command = run_mypyc_build.build_mypyc_command()

    assert command == [
        sys.executable,
        "build/setup.py",
        "build_ext",
        "--inplace",
        "--force",
    ]
    assert "dank_mids/_batch.py" in MYPYC_BUILD_ARGS
    assert "dank_mids/helpers/_retry_mechanics.py" in MYPYC_BUILD_ARGS
    assert "dank_mids/stats/__init__.py" in MYPYC_BUILD_ARGS
    assert "dank_mids/_vendor/aiolimiter/src" in MYPYC_BUILD_ARGS
    assert "--pretty" in MYPYC_BUILD_ARGS
    assert "--disable-error-code=unused-ignore" in MYPYC_BUILD_ARGS
    assert "--disable-error-code=arg-type" in MYPYC_BUILD_ARGS
    assert "--disable-error-code=override" in MYPYC_BUILD_ARGS


def test_mypyc_setup_uses_deterministic_runtime_group_name() -> None:
    rendered_setup = MYPYC_SETUP.format(
        build_args=MYPYC_BUILD_ARGS,
        group_name=MYPYC_GROUP_NAME,
    )

    assert MYPYC_GROUP_NAME == "dank_mids"
    assert MYPYC_RUNTIME_MODULE == "dank_mids__mypyc"
    assert "group_name='dank_mids'" in rendered_setup


def test_mypyc_targets_expand_vendored_aiolimiter_sources() -> None:
    expanded_targets = expand_mypyc_targets(REPO_ROOT)

    assert "dank_mids/_vendor/aiolimiter/src/aiolimiter/__init__.py" in expanded_targets
    assert "dank_mids/_vendor/aiolimiter/src/aiolimiter/leakybucket.py" in expanded_targets


def test_build_dependencies_come_from_pyproject(tmp_path) -> None:
    (tmp_path / "pyproject.toml").write_text(
        """
[dependency-groups]
build = [
    "example==1",
    "other==2",
]
""".lstrip()
    )

    assert build_dependencies(tmp_path) == ["example==1", "other==2"]


def test_mypyc_build_dependency_surface_allows_build_only_runtime_overlap() -> None:
    preflight_mypyc_build_dependency_surface(
        REPO_ROOT,
        installed_names=[
            "aiolimiter",
            "cchecksum",
            "eth-retry",
            "eth-typing",
            "ez-a-sync",
            "faster-eth-abi",
            "faster-eth-utils",
            "faster-hexbytes",
            "librt",
            "typed-envs",
        ],
    )


def test_mypyc_build_dependency_surface_rejects_runtime_only_dependencies() -> None:
    with pytest.raises(RuntimeError) as exc_info:
        preflight_mypyc_build_dependency_surface(
            REPO_ROOT,
            installed_names=[
                "aiofiles",
                "evmspec",
                "multicall",
                "web3",
            ],
        )

    message = str(exc_info.value)
    assert "build-only dependency surface" in message
    assert "uv run --only-group build python scripts/run_mypyc_build.py" in message
    assert "dev/runtime env" in message
    assert "aiofiles, evmspec, multicall, web3" in message


def test_run_mypyc_preflights_before_writing_setup_or_invoking_subprocess(
    tmp_path, monkeypatch
) -> None:
    calls: list[Path] = []

    def fail_preflight(root: Path) -> None:
        calls.append(root)
        raise RuntimeError("contaminated")

    def fake_run(*args, **kwargs) -> None:
        raise AssertionError("subprocess.run should not be reached")

    monkeypatch.setattr(
        mypyc_targets,
        "preflight_mypyc_build_dependency_surface",
        fail_preflight,
    )
    monkeypatch.setattr(mypyc_targets.subprocess, "run", fake_run)

    with pytest.raises(RuntimeError, match="contaminated"):
        mypyc_targets.run_mypyc(tmp_path)

    assert calls == [tmp_path]
    assert not (tmp_path / "build" / "setup.py").exists()


def test_mypyc_runtime_artifacts_find_top_level_runtime(tmp_path) -> None:
    suffix = extension_suffix()
    runtime = tmp_path / f"{MYPYC_RUNTIME_MODULE}{suffix}"
    nested_dir = tmp_path / "dank_mids"
    nested_dir.mkdir()
    nested_runtime = nested_dir / f"nested__mypyc{suffix}"
    wrong_suffix = tmp_path / "abc123__mypyc.test.so"
    runtime.write_text("runtime")
    nested_runtime.write_text("nested")
    wrong_suffix.write_text("wrong")

    assert mypyc_runtime_artifacts(tmp_path) == [runtime]
    assert mypyc_runtime_force_include(tmp_path) == {str(runtime): runtime.name}


def test_main_runs_compile_without_installing_dependencies(monkeypatch) -> None:
    calls: list[Path] = []

    def fake_run(root: Path) -> None:
        calls.append(root)

    monkeypatch.setattr(run_mypyc_build, "run_mypyc", fake_run)

    rc = run_mypyc_build.main([])

    assert rc == 0
    assert calls == [run_mypyc_build.ROOT]


def test_clean_source_extensions_delegates_to_shared_cleanup(tmp_path, monkeypatch) -> None:
    calls: list[Path] = []

    def fake_clean(root: Path) -> None:
        calls.append(root)

    monkeypatch.setattr(clean_source_extensions, "ROOT", tmp_path)
    monkeypatch.setattr(clean_source_extensions, "clean_compiled_artifacts", fake_clean)

    rc = clean_source_extensions.main()

    assert rc == 0
    assert calls == [tmp_path]


def test_copy_compiled_artifacts_preserves_source_tree_paths(tmp_path, monkeypatch) -> None:
    root = tmp_path / "repo"
    artifact_dir = tmp_path / "artifacts"
    package_dir = root / "dank_mids"
    package_dir.mkdir(parents=True)
    runtime = root / "abc123__mypyc.test.so"
    batch = package_dir / "_batch.test.so"
    runtime.write_text("runtime")
    batch.write_text("batch")

    def fake_artifact_patterns(root_arg: Path) -> list[str]:
        assert root_arg == root
        return ["/*__mypyc*.so", "/dank_mids/*.so"]

    monkeypatch.setattr(
        build_source_extensions, "compiled_artifact_patterns", fake_artifact_patterns
    )

    copied = build_source_extensions.copy_compiled_artifacts(root, artifact_dir)

    assert sorted(path.as_posix() for path in copied) == [
        "abc123__mypyc.test.so",
        "dank_mids/_batch.test.so",
    ]
    assert (artifact_dir / "abc123__mypyc.test.so").read_text() == "runtime"
    assert (artifact_dir / "dank_mids" / "_batch.test.so").read_text() == "batch"


def _write_wheel(path: Path, names: list[str]) -> None:
    with zipfile.ZipFile(path, "w") as wheel:
        for name in names:
            wheel.writestr(name, "")


def test_check_mypyc_wheel_requires_top_level_runtime_artifact(tmp_path) -> None:
    wheel = tmp_path / "pkg.whl"
    _write_wheel(wheel, ["dank_mids/_batch.test.so"])

    assert check_mypyc_wheel.check_wheel(wheel, ["dank_mids/_batch.py"]) == [
        "pkg.whl: missing top-level dank_mids__mypyc runtime artifact"
    ]


def test_check_mypyc_wheel_rejects_hash_named_runtime_artifact(tmp_path) -> None:
    wheel = tmp_path / "pkg.whl"
    _write_wheel(
        wheel,
        [
            "f5ba6e22fbbacf90552f__mypyc.test.so",
            "dank_mids/_batch.test.so",
        ],
    )

    assert check_mypyc_wheel.check_wheel(wheel, ["dank_mids/_batch.py"]) == [
        "pkg.whl: missing top-level dank_mids__mypyc runtime artifact"
    ]


def test_check_mypyc_wheel_accepts_top_level_runtime_artifact(tmp_path) -> None:
    wheel = tmp_path / "pkg.whl"
    _write_wheel(
        wheel,
        [
            "dank_mids__mypyc.test.so",
            "dank_mids/_batch.test.so",
        ],
    )

    assert check_mypyc_wheel.check_wheel(wheel, ["dank_mids/_batch.py"]) == []


def test_clean_build_intermediates_removes_ignored_build_dirs(tmp_path) -> None:
    build_dir = tmp_path / "build"
    lib_dir = build_dir / "lib.linux-x86_64-cpython-313"
    temp_dir = build_dir / "temp.linux-x86_64-cpython-313"
    tracked_source = build_dir / "__native.c"
    lib_dir.mkdir(parents=True)
    temp_dir.mkdir()
    tracked_source.write_text("generated")
    (lib_dir / "stale.so").write_text("stale")
    (temp_dir / "stale.o").write_text("stale")

    removed = build_source_extensions.clean_build_intermediates(tmp_path)

    assert sorted(path.as_posix() for path in removed) == [
        "build/lib.linux-x86_64-cpython-313",
        "build/temp.linux-x86_64-cpython-313",
    ]
    assert not lib_dir.exists()
    assert not temp_dir.exists()
    assert tracked_source.read_text() == "generated"


def test_build_source_extensions_main_cleans_builds_and_stages(
    tmp_path, monkeypatch, capsys
) -> None:
    calls: list[tuple[str, Path] | tuple[str, Path, Path]] = []
    artifact_dir = tmp_path / "artifacts"

    def fake_clean(root: Path) -> None:
        calls.append(("clean", root))

    def fake_run(root: Path) -> None:
        calls.append(("build", root))

    def fake_clean_intermediates(root: Path) -> list[Path]:
        calls.append(("intermediates", root))
        return [Path("build/lib.test")]

    def fake_copy(root: Path, destination: Path) -> list[Path]:
        calls.append(("copy", root, destination))
        return [Path("dank_mids/_batch.test.so")]

    monkeypatch.setattr(build_source_extensions, "ROOT", tmp_path)
    monkeypatch.setattr(build_source_extensions, "clean_compiled_artifacts", fake_clean)
    monkeypatch.setattr(
        build_source_extensions, "clean_build_intermediates", fake_clean_intermediates
    )
    monkeypatch.setattr(build_source_extensions, "run_mypyc", fake_run)
    monkeypatch.setattr(build_source_extensions, "copy_compiled_artifacts", fake_copy)

    rc = build_source_extensions.main(["--artifact-dir", str(artifact_dir)])

    assert rc == 0
    assert calls == [
        ("clean", tmp_path),
        ("intermediates", tmp_path),
        ("build", tmp_path),
        ("copy", tmp_path, artifact_dir),
    ]
    assert capsys.readouterr().out == "staged 1 compiled extension artifact(s)\n"
