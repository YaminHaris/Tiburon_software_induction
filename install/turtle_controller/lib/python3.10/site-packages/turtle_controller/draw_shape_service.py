import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from turtle_interfaces.srv import DrawShape   # Replace 'my_package' with your actual package name
import math
import time

class DrawShapeService(Node):
    def __init__(self):
        super().__init__('draw_shape_service')
        self.publisher = self.create_publisher(Twist, '/turtle1/cmd_vel', 10)
        self.service = self.create_service(DrawShape, '/draw_shape', self.draw_shape_callback)
        self.get_logger().info("DrawShape service ready.")

    def draw_shape_callback(self, request, response):
        shape = request.shape.lower().strip()
        size = request.size
        self.get_logger().info(f"Drawing {shape} with size {size}")

        try:
            if shape == "square":
                self.draw_polygon(4, size)
            elif shape == "triangle":
                self.draw_polygon(3, size)
            elif shape == "pentagon":
                self.draw_polygon(5, size)
            else:
                response.success = False
                response.message = f"Unknown shape: {shape}"
                self.get_logger().warn(response.message)
                return response

            response.success = True
            response.message = f"{shape.capitalize()} drawn successfully."
        except Exception as e:
            response.success = False
            response.message = f"Error drawing shape: {e}"
            self.get_logger().error(response.message)

        return response

    def draw_polygon(self, sides, size):
        twist = Twist()
        linear_speed = 1.0
        angular_speed = 2 * math.pi / sides  # Full circle divided by number of sides

        for _ in range(sides):
            # Move forward
            twist.linear.x = linear_speed
            twist.angular.z = 0.0
            self.publisher.publish(twist)
            time.sleep(size / linear_speed)

            # Stop and turn
            twist.linear.x = 0.0
            self.publisher.publish(twist)
            time.sleep(0.1)

            twist.angular.z = angular_speed
            self.publisher.publish(twist)
            time.sleep(1.0)

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

