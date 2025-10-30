import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose
from math import sqrt
from rcl_interfaces.msg import SetParametersResult


class TurtleSpiral(Node):
    def __init__(self):
        super().__init__('turtle_spiral')

        # Publisher and subscriber
        self.publisher_ = self.create_publisher(Twist, '/turtle1/cmd_vel', 10)
        self.subscription = self.create_subscription(Pose, '/turtle1/pose', self.pose_callback, 10)

        # Declare parameters
        self.declare_parameter('spiral_linear_velocity', 0.5)
        self.declare_parameter('spiral_angular_velocity', 1.0)

        # Internal state
        self.center = (5.544, 5.544)
        self.max_radius = 5.5
        self.linear_speed = 0.0
        self.linear_growth = 0.1
        self.pose = None

        # Register callback for dynamic parameter updates
        self.add_on_set_parameters_callback(self.param_callback)

        # Timer for movement
        self.timer = self.create_timer(0.1, self.spiral_motion)

    def pose_callback(self, msg):
        self.pose = msg

    def param_callback(self, params):
        for param in params:
            if param.name == 'spiral_linear_velocity':
                self.get_logger().info(f"Updated spiral_linear_velocity: {param.value}")
            elif param.name == 'spiral_angular_velocity':
                self.get_logger().info(f"Updated spiral_angular_velocity: {param.value}")
        return SetParametersResult(successful=True)

    def spiral_motion(self):
        if self.pose is None:
            return

        distance = sqrt((self.pose.x - self.center[0]) ** 2 + (self.pose.y - self.center[1]) ** 2)

        if distance > self.max_radius:
            twist = Twist()
            self.publisher_.publish(twist)
            self.get_logger().info("Spiral complete.")
            self.timer.cancel()
            return

        # Gradual outward spiral growth
        self.linear_speed += self.linear_growth * 0.1

        # Use current parameter values
        linear_base = self.get_parameter('spiral_linear_velocity').value
        angular_speed = self.get_parameter('spiral_angular_velocity').value

        twist = Twist()
        twist.linear.x = linear_base + self.linear_speed
        twist.angular.z = angular_speed
        self.publisher_.publish(twist)

        self.get_logger().info(f"Radius={distance:.2f}, Linear={twist.linear.x:.2f}, Angular={twist.angular.z:.2f}")

def main(args=None):
    rclpy.init(args=args)
    node = TurtleSpiral()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

