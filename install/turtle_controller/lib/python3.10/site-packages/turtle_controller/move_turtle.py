import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose
from math import radians

class TurtleMover(Node):
    def __init__(self):
        super().__init__('turtle_mover')

        # Publisher and subscriber
        self.publisher_ = self.create_publisher(Twist, '/turtle1/cmd_vel', 10)
        self.subscription = self.create_subscription(Pose, '/turtle1/pose', self.position_callback, 10)

        # Parameters
        self.linear_speed = 1.5             # units per second
        self.angular_speed = radians(45)    # rad/s (45 deg/s)

        # Internal state
        self.position = None
        self.state = "move"                 # alternates between 'move' and 'rotate'
        self.current_step = 0
        self.start_time = None
        self.target_duration = 0.0

        # Timer callback
        self.timer = self.create_timer(0.1, self.move_turtle)

    def position_callback(self, msg):
        self.position = msg

    # Move forward for a certain distance
    def move_forward(self, distance):
        twist = Twist()

        if self.start_time is None:
            self.start_time = self.get_clock().now()
            self.target_duration = distance / self.linear_speed
            self.get_logger().info(f"Moving forward for {distance:.2f} units")

        elapsed = (self.get_clock().now() - self.start_time).nanoseconds / 1e9

        if elapsed < self.target_duration:
            twist.linear.x = self.linear_speed
            self.publisher_.publish(twist)
        else:
            twist.linear.x = 0.0
            self.publisher_.publish(twist)
            self.start_time = None
            self.state = "rotate"

    # Rotate by a given angle (degrees)
    def rotate_by(self, angle_deg):
        twist = Twist()
        angle_rad = radians(abs(angle_deg))
        direction = 1.0 if angle_deg > 0 else -1.0

        if self.start_time is None:
            self.start_time = self.get_clock().now()
            self.target_duration = angle_rad / self.angular_speed
            self.get_logger().info(f"Rotating by {angle_deg:.2f} degrees")

        elapsed = (self.get_clock().now() - self.start_time).nanoseconds / 1e9

        if elapsed < self.target_duration:
            twist.angular.z = direction * self.angular_speed
            self.publisher_.publish(twist)
        else:
            twist.angular.z = 0.0
            self.publisher_.publish(twist)
            self.start_time = None
            self.state = "move"
            self.current_step += 1

    # Main movement logic
    def move_turtle(self):
        if self.position is None:
            return

        if self.current_step >= 5:
            twist = Twist()
            self.publisher_.publish(twist)
            self.get_logger().info("Star drawing complete.")
            self.timer.cancel()
            return

        if self.state == "move":
            self.move_forward(2.0)
        elif self.state == "rotate":
            self.rotate_by(-144)  # clockwise rotation for star pattern

def main(args=None):
    rclpy.init(args=args)
    node = TurtleMover()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

