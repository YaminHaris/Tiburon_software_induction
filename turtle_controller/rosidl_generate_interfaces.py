from rosidl_default_generators import generate_interfaces

generate_interfaces(
    package_name='turtle_controller',
    interface_files=['srv/DrawShape.srv'],
)

