from setuptools import find_packages, setup
import os
from glob import glob

package_name = 'task_controller'

setup(
    name=package_name,
    version='60.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
         ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/'+ package_name+ 'srv/',glob('srv/*.srv')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='samiksha',
    maintainer_email='samiksha@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    entry_points={
        'console_scripts': [
          "control=task_controller.control_turtle:main",
          "circle=task_controller.circle_turtle:main",
          "letter=task_controller.letter_turtle:main",
          "service=task_controller.service_doc:main",
          "client=task_controller.client_doc:main",
          "polygon=task_controller.polygon_turtle:main",
          'polygon_service_server = task_controller.polygon_service_server:main',
          'polygon_service_client = task_controller.polygon_service_client:main',

        ],
    },
)
