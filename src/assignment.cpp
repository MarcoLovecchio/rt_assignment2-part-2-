#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "nav_msgs/msg/odometry.hpp"

class Motion : public rclcpp::Node{
public:
    Motion()
    : Node("Motion"){
        pub = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);
        sub = this->create_subscription<nav_msgs::msg::Odometry>(
            "/odom", 10, std::bind(&Motion::odomCallback, this, std::placeholders::_1));
    }

private:
    void odomCallback(const nav_msgs::msg::Odometry::SharedPtr msg){
        auto pose = msg->pose.pose.position;

        geometry_msgs::msg::Twist vel;

        if (pose.x > 6.0){
            vel.linear.x = 1.0;
            vel.angular.z = 1.0;
        }
        else if (pose.x < 0){
            vel.linear.x = 1.0;
            vel.angular.z = -1.0;
        }
        else{
            vel.linear.x = 1.0;
            vel.angular.z = 0.0;
        }
        pub->publish(vel);
    }

    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr pub;
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr sub;
};

int main(int argc, char *argv[]){
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Motion>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
