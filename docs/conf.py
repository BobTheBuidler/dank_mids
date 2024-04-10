# Configuration file for the Sphinx documentation builder.
#
# For the full list of built-in configuration values, see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Project information -----------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#project-information

import os
import sys
from brownie import network

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
