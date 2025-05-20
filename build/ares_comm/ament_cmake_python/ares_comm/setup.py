from setuptools import find_packages
from setuptools import setup

setup(
    name='ares_comm',
    version='0.0.0',
    packages=find_packages(
        include=('ares_comm', 'ares_comm.*')),
)
