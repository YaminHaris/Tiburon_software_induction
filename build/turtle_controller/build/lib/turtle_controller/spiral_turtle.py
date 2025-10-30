import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose
from math import sqrt

class TurtleSpiral(Node):
    def __init__(self):
        super().__init__('turtle_spiral')

        # Publisher and subscriber
        self.publisher_ = self.create_publisher(Twist, '/turtle1/cmd_vel', 10)
        self.subscription = self.create_subscription(Pose, '/turtle1/pose', self.pose_callback, 10)

        # Parameters
        self.angular_speed = 1.0      # rad/s
        self.linear_growth = 0.1      # how much to increase linear speed per second
        self.max_radius = 5.5         # stop when turtle distance from (0,0) > this
        self.center = (5.544, 5.544)  # turtlesim default center
        self.linear_speed = 0.0

        self.pose = None
        self.timer = self.create_timer(0.1, self.spiral_motion)

    def pose_callback(self, msg):
        self.pose = msg

    def spiral_motion(self):
        if self.pose is None:
            return

        # Compute distance from center
        distance = sqrt((self.pose.x - self.center[0])**2 + (self.pose.y - self.center[1])**2)

        # Stop if out of bounds
        if distance > self.max_radius:
            twist = Twist()
            self.publisher_.publish(twist)
            self.get_logger().info("Spiral complete.")
            self.timer.cancel()
            return

        # Increase linear speed gradually to create spiral effect
        self.linear_speed += self.linear_growth * 0.1  # increase per timer tick

        twist = Twist()
        twist.linear.x = self.linear_speed
        twist.angular.z = self.angular_speed
        self.publisher_.publish(twist)

        self.get_logger().info(f"Radius={distance:.2f}, Linear={self.linear_speed:.2f}")

def main(args=None):
    rclpy.init(args=args)
    node = TurtleSpiral()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

