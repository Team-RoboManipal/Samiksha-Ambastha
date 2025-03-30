from setuptools import find_packages, setup
import os
from glob import glob

package_name = 'urdf_tutorial_r2d2'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        (os.path.join('share', package_name, 'launch'), glob(os.path.join('launch', '*launch.[pxy][yma]*'))),
        (os.path.join('share', package_name), glob('urdf/*')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='samiksha',
    maintainer_email='samikshaambastha9308@gmail.com',
    description='A package to publish robot state in ROS 2 for the R2D2 robot simulation.',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
           'state_publisher = urdf_tutorial_r2d2.state_publisher:main'
        ],
    },
)
