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

network.connect('mainnet')

project = 'dank_mids'
copyright = '2024, BobTheBuidler'
author = 'BobTheBuidler'

# -- General configuration ---------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#general-configuration

extensions = [
    'sphinx.ext.autodoc',
    'sphinx.ext.napoleon',
    'sphinx.ext.intersphinx',
]

templates_path = ['_templates']
exclude_patterns = ['_build', 'Thumbs.db', '.DS_Store']

intersphinx_mapping = {
    'a_sync': ('https://bobthebuidler.github.io/ez-a-sync', None),
    'brownie': ('https://eth-brownie.readthedocs.io/en/stable/', None),
    'hexbytes': ('https://hexbytes.readthedocs.io/en/stable/', None),
    'python': ('https://docs.python.org/3', None),
    'typing_extensions': ('https://typing-extensions.readthedocs.io/en/latest/', None),
    'web3': ('https://web3py.readthedocs.io/en/stable/', None),
}

# -- Options for HTML output -------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#options-for-html-output

html_theme = 'sphinx_rtd_theme'
html_static_path = ['_static']

autodoc_default_options = {
    'special-members': ','.join([
        '__init__',
        '__call__',
        '__getitem__',
        '__iter__',
        '__aiter__',
        '__next__',
        '__anext__',
    ]),
    'inherited-members': True,
    'member-order': 'groupwise',
    # hide private methods that aren't relevant to us here
    'exclude-members': ','.join([
        '__new__',
        '_abc_impl',
        '_fget',
        '_fset',
        '_fdel',
        '_ASyncSingletonMeta__instances',
        '_ASyncSingletonMeta__lock',
    ]),
}
autodoc_typehints = "description"
# Don't show class signature with the class' name.
autodoc_class_signature = "separated"

automodule_generate_module_stub = True

sys.path.insert(0, os.path.abspath('./dank_mids'))


def skip_specific_members(app, what, name, obj, skip, options):
    """
    Function to exclude specific members for a particular module.
    """
    exclusions = {
        'dank_mids.exceptions': {'__init__', 'args', 'with_traceback'},
        'dank_mids.types': {'__call__', '__iter__', 'get', 'update', 'clear', 'copy', 'keys', 'values', 'items', 'fromkeys', 'pop', 'popitem', 'setdefault'},
        'dank_mids.brownie_patch.contract': {'__call__', },
    }
    
    current_module = getattr(obj, '__module__', None)
    logger.info(f"module: {current_module}  obj: {obj}")
    if current_module in exclusions and name in exclusions[current_module]:
        return True
    return skip

def setup(app):
    app.connect('autodoc-skip-member', skip_specific_members)