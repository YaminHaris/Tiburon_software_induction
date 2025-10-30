from setuptools import setup

package_name = 'turtle_controller'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='yami',
    maintainer_email='yami@todo.todo',
    description='TODO: Package description',
    license='TODO',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'draw_shape_service = turtle_controller.draw_shape_service:main',
            'move_turtle = turtle_controller.move_turtle:main',
            'spiral_turtle = turtle_controller.spiral_turtle:main',
            'spiral_turtle_parameters = turtle_controller.spiral_turtle_parameters:main',

        ],
    },
)

