from __future__ import annotations

import pathlib
import sys
from typing import Any

from hatchling.builders.hooks.plugin.interface import BuildHookInterface

ROOT = pathlib.Path(__file__).resolve().parent
sys.path.insert(0, str(ROOT))
from scripts.ci.mypyc_targets import BUILD_DEPENDENCIES  # noqa: E402
from scripts.ci.mypyc_targets import (
    clean_compiled_artifacts,
    compiled_artifact_patterns,
    expand_mypyc_targets,
    run_mypyc,
)


class CustomBuildHook(BuildHookInterface):
    def dependencies(self) -> list[str]:
        return BUILD_DEPENDENCIES

    def initialize(self, version: str, build_data: dict[str, Any]) -> None:
        if self.target_name != "wheel" or version == "editable":
            return

        root = pathlib.Path(self.root)
        expand_mypyc_targets(root)
        clean_compiled_artifacts(root)
        run_mypyc(root)
        build_data["pure_python"] = False
        build_data["infer_tag"] = True
        build_data.setdefault("artifacts", []).extend(compiled_artifact_patterns(root))
