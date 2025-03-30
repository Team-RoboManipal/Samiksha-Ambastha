from setuptools import find_packages
from setuptools import setup

setup(
    name='rviz_plugin_tutorial',
    version='0.0.0',
    packages=find_packages(
        include=('rviz_plugin_tutorial', 'rviz_plugin_tutorial.*')),
)
