# Configuration file for the Sphinx documentation builder.
#
# For the full list of built-in configuration values, see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Project information -----------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#project-information

import os
import sys

from brownie import network
from sphinx.util import logging

logger = logging.getLogger(__name__)

network.connect("mainnet")

project = "dank_mids"
copyright = "2024, BobTheBuidler"
author = "BobTheBuidler"

# -- General configuration ---------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#general-configuration

extensions = [
    "sphinx.ext.autodoc",
    "sphinx.ext.napoleon",
    "sphinx.ext.intersphinx",
]

templates_path = ["_templates"]
exclude_patterns = ["_build", "Thumbs.db", ".DS_Store"]

intersphinx_mapping = {
    "a_sync": ("https://bobthebuidler.github.io/ez-a-sync", None),
    "brownie": ("https://eth-brownie.readthedocs.io/en/stable/", None),
    "dictstruct": ("https://bobthebuidler.github.io/dictstruct", None),
    "evmspec": ("https://bobthebuidler.github.io/evmspec", None),
    "hexbytes": ("https://hexbytes.readthedocs.io/en/stable/", None),
    "python": ("https://docs.python.org/3", None),
    "typed_envs": ("https://bobthebuidler.github.io/typed-envs/", None),
    "typing_extensions": ("https://typing-extensions.readthedocs.io/en/latest/", None),
    "web3": ("https://web3py.readthedocs.io/en/stable/", None),
}

# -- Options for HTML output -------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#options-for-html-output

html_theme = "sphinx_rtd_theme"
html_static_path = ["_static"]

autodoc_default_options = {
    "special-members": ",".join(
        [
            "__init__",
            "__call__",
            "__getitem__",
            "__iter__",
            "__aiter__",
            "__next__",
            "__anext__",
        ]
    ),
    "inherited-members": True,
    "member-order": "groupwise",
    # hide private methods that aren't relevant to us here
    "exclude-members": ",".join(
        [
            "__new__",
            "_abc_impl",
            "_fget",
            "_fset",
            "_fdel",
            "_ASyncSingletonMeta__instances",
            "_ASyncSingletonMeta__lock",
        ]
    ),
}
autodoc_typehints = "description"
# Don't show class signature with the class' name.
autodoc_class_signature = "separated"

automodule_generate_module_stub = True

sys.path.insert(0, os.path.abspath("./dank_mids"))


def skip_specific_members(app, what, name, obj, skip, options):
    """
    Determine whether specific members should be excluded for a particular module.

    This function is used to customize the selection of members to exclude
    when generating documentation for Sphinx. It uses predefined exclusions
    based on module and member name, as well as conditions for skipping 
    certain members of NewType objects and Exception subclasses.

    Parameters:
    - app: Sphinx application object.
    - what: The type of the object which the docstring belongs to 
      (e.g., 'module', 'class').
    - name: The name of the object.
    - obj: The object itself.
    - skip: A boolean indicating if the member should be skipped.
    - options: The options given to the directive: an object with attributes 
      'inherited_members', 'undoc_members', 'show_inheritance', and 'noindex'
      that are true if the flag option of same name was given to the 
      auto directive.

    Returns:
    - A boolean value indicating whether to skip the member.
    """
    exclusions = {
        "dank_mids.types": {
            "__iter__",
            "get",
            "update",
            "clear",
            "copy",
            "keys",
            "values",
            "items",
            "fromkeys",
            "pop",
            "popitem",
            "setdefault",
        },
    }

    current_module = getattr(obj, "__module__", None)
    logger.info(f"module: {current_module}  name: {name}  obj: {obj}")
    if current_module in exclusions and name in exclusions[current_module]:
        return True

    # Skip the __init__ and __call__ members of any NewType objects we defined.
    if (
        current_module == "typing"
        and hasattr(obj, "__self__")
        and type(obj.__self__).__name__ == "NewType"
        and name in ["__init__", "__call__"]
    ):
        return True

    # Skip the __init__, args, and with_traceback members of all Exceptions
    if (
        current_module is None
        and hasattr(obj, "__objclass__")
        and issubclass(obj.__objclass__, BaseException)
        and name in ["__init__", "args", "with_traceback"]
    ):
        return True

    return skip


def setup(app):
    """
    Set up the Sphinx application.

    This function is used to connect the 'autodoc-skip-member' event to the
    custom `skip_specific_members` function, allowing specific members to be
    conditionally excluded from Sphinx documentation based on the logic 
    defined in `skip_specific_members`.

    Parameters:
    - app: Sphinx application object.
    """
    app.connect("autodoc-skip-member", skip_specific_members)
