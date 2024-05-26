# Configuration file for the Sphinx documentation builder.
#
# For the full list of built-in configuration values, see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Project information -----------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#project-information
import subprocess, os

project = 'Dook'
copyright = '2024, Dook Team'
author = 'Dook Team'
release = '0.1'

# -- General configuration ---------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#general-configuration

extensions = ['breathe']

breathe_default_project = 'Dook'

templates_path = ['_templates']
exclude_patterns = []

# Check if we're running on Read the Docs' servers
read_the_docs_build = os.environ.get('READTHEDOCS', None) == 'True'

breathe_projects = {}

if read_the_docs_build:
    with open('../Doxyfile', 'r') as f:
        data = f.read()
    with open('../Doxyfile', 'w') as f:
        f.write(data.replace('INPUT                  = ../src', 'INPUT                  = ../../src'))
    subprocess.call('doxygen Doxyfile', shell=True, cwd="../")
    breathe_projects['Dook'] =  '../xml'



# -- Options for HTML output -------------------------------------------------
# https://www.sphinx-doc.org/en/master/usage/configuration.html#options-for-html-output

html_theme = 'sphinx_rtd_theme'
html_static_path = ['_static']
