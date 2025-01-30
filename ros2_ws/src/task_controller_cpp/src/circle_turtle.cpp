#include <memory>
#include <functional>
#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <turtlesim/msg/pose.hpp>
#include <cmath>
#include <cstdlib>
#include <chrono>

using namespace std::chrono_literals;

class DrawCircle : public rclcpp::Node {
public:
    DrawCircle(float radius, float angular_speed)
        : Node("circle_drawer"), radius_(radius), angular_speed_(angular_speed)
    {
        publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);
        subscriber_ = this->create_subscription<turtlesim::msg::Pose>("/turtle1/pose", 10, std::bind(&DrawCircle::pose_callback, this, std::placeholders::_1));
        timer_ = this->create_wall_timer(100ms, std::bind(&DrawCircle::draw_circle, this));

        linear_speed_ = angular_speed_ * radius_;
     
        RCLCPP_INFO(this->get_logger(), "Drawing a circle with radius %.2f m", radius_);
    }

private:
    void pose_callback(const turtlesim::msg::Pose::SharedPtr msg)
    {
        pose_ = *msg;
    }

    void draw_circle()
    {
        geometry_msgs::msg::Twist vel_msg;
        vel_msg.linear.x = linear_speed_;  
        vel_msg.angular.z = angular_speed_;  

        publisher_->publish(vel_msg);

        // Log debug info
        RCLCPP_INFO(this->get_logger(), "Linear Speed: %.2f, Angular Speed: %.2f", vel_msg.linear.x, vel_msg.angular.z);
    }

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
    rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr subscriber_;
    turtlesim::msg::Pose pose_;
    float radius_, angular_speed_, linear_speed_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);

    
    // Get radius and angular_speed from command line arguments
    float radius = std::stof(argv[1]);
    float angular_speed = std::stof(argv[2]);

    // Create and spin the node
    rclcpp::spin(std::make_shared<DrawCircle>(radius, angular_speed));

    rclcpp::shutdown();
    return 0;
}
