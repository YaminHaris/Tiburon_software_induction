import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from my_robot_interfaces.srv import DrawShape  # Import your custom srv
import math
import time

class DrawShapeService(Node):
    def __init__(self):
        super().__init__('draw_shape_service')
        self.publisher = self.create_publisher(Twist, '/turtle1/cmd_vel', 10)
        self.service = self.create_service(DrawShape, '/draw_shape', self.draw_shape_callback)

    def draw_shape_callback(self, request, response):
        shape = request.shape.lower()  # Expecting 'square' or 'triangle'
        size = request.size

        self.get_logger().info(f"Received request to draw {shape} with size {size}")

        success = False
        try:
            if shape == "square":
                self.draw_square(size)
                success = True
            elif shape == "triangle":
                self.draw_triangle(size)
                success = True
            else:
                self.get_logger().warn(f"Unknown shape: {shape}")
                success = False
        except Exception as e:
            self.get_logger().error(f"Error drawing shape: {e}")
            success = False

        response.success = success
        response.message = f"Drew {shape} with size {size}" if success else "Failed to draw shape"
        return response

    def draw_square(self, size):
        self.draw_polygon(4, size)

    def draw_triangle(self, size):
        self.draw_polygon(3, size)

    def draw_polygon(self, sides, size):
        twist = Twist()
        linear_speed = 1.0
        angular_speed = math.pi / 2  # 90 degrees per second approx for turning
        if sides == 3:
            angular_speed = 2 * math.pi / 3  # 120 degrees for triangle turns

        angle = 2 * math.pi / sides  # angle to turn after each side

        for _ in range(sides):
            # Move forward side
            twist.linear.x = linear_speed
            twist.angular.z = 0.0
            self.publisher.publish(twist)
            time.sleep(size / linear_speed)

            # Stop linear motion before rotate
            twist.linear.x = 0.0
            self.publisher.publish(twist)
            time.sleep(0.1)

            # Rotate
            twist.angular.z = angular_speed
            self.publisher.publish(twist)
            time.sleep(angle / angular_speed)

            # Stop rotation
            twist.angular.z = 0.0
            self.publisher.publish(twist)
            time.sleep(0.1)

def main(args=None):
    rclpy.init(args=args)
    node = DrawShapeService()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == "__main__":
    main()

