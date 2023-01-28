# type: ignore

from setuptools import find_packages, setup

with open(requirements_filename, "r") as f:
    requirements = list(map(str.strip, f.read().split("\n")))[:-1]

setup(
    name='dank_mids',
    packages=find_packages(),
    use_scm_version={
        "root": ".",
        "relative_to": __file__,
        "local_scheme": "no-local-version",
        "version_scheme": "python-simplified-semver",
    },
    description='Multicall batching middleware for asynchronous scripts using web3.py',
    author='BobTheBuidler',
    author_email='bobthebuidlerdefi@gmail.com',
    url='https://github.com/BobTheBuidler/dank_mids',
    license='MIT',
    install_requires=requirements,
    setup_requires=[
        'setuptools_scm',
    ],
    package_data={
        "dank_mids": ["py.typed"],
    },
)
