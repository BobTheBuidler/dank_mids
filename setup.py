# type: ignore

from setuptools import find_packages, setup

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
    install_requires=[
        "bobs_lazy_logging>=0.0.4",
        "multicall>=0.5.1",
    ],
    setup_requires=[
        'setuptools_scm',
    ],
    package_data={
        "dank_mids": ["py.typed"],
    },
)
