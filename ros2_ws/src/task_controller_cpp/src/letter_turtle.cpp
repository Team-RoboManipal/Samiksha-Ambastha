#include <memory>
#include <cmath>
#include <cstdlib>
#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <turtlesim/msg/pose.hpp>

using namespace std::chrono_literals;

class DrawLetterD : public rclcpp::Node {
public:
    DrawLetterD(float radius, float angular_speed)
        : Node("draw_letter_d"), radius_(radius), angular_speed_(angular_speed) {
        publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);
        subscriber_ = this->create_subscription<turtlesim::msg::Pose>("/turtle1/pose", 10, std::bind(&DrawLetterD::pose_callback, this, std::placeholders::_1));
        timer_ = this->create_wall_timer(100ms, std::bind(&DrawLetterD::control_loop, this));  // Control loop at 0.1s interval

        linear_speed_ = angular_speed_ * radius_; // Linear speed (m/s)
        target_angle_ = M_PI;  // Target angle for semi-circle (180 degrees)
        angle_covered_ = 0.0;  // Tracks the angle covered for the semi-circle
        distance_tol_ = 0.1;   // Distance tolerance to determine arrival at the spawn point

        state_ = "start";
    }

private:
    void pose_callback(const turtlesim::msg::Pose::SharedPtr msg) {
        pose_ = *msg;
        if (state_ == "start" && spawn_x_ == 0.0 && spawn_y_ == 0.0) {
            // Save the spawn position and initial orientation
            spawn_x_ = msg->x;
            spawn_y_ = msg->y;
            start_theta_ = msg->theta;
            state_ = "draw_semi_circle";
            RCLCPP_INFO(this->get_logger(), "Spawn point: x=%.2f, y=%.2f, theta=%.2f", spawn_x_, spawn_y_, start_theta_);
        }
    }

    void control_loop() {
        geometry_msgs::msg::Twist vel_msg;

        if (state_ == "draw_semi_circle") {
            // Move in a semi-circle
            vel_msg.linear.x = linear_speed_;
            vel_msg.angular.z = angular_speed_;
            angle_covered_ += std::abs(angular_speed_ * 0.1);  // Update the angle covered

            if (angle_covered_ >= target_angle_) {
                // Stop the semi-circle motion
                vel_msg.linear.x = 0.0;
                vel_msg.angular.z = 0.0;
                state_ = "return_to_spawn";
                RCLCPP_INFO(this->get_logger(), "Semi-circle complete. Returning to spawn.");
            }

        } else if (state_ == "return_to_spawn") {
            // Compute distance and angle to spawn point
            float distance = std::sqrt(std::pow(spawn_x_ - pose_.x, 2) + std::pow(spawn_y_ - pose_.y, 2));
            float theta = std::atan2(spawn_y_ - pose_.y, spawn_x_ - pose_.x);
            float angle_error = theta - pose_.theta;

            if (std::abs(angle_error) > 0.1) {
                // Rotate to face the spawn point
                vel_msg.angular.z = angle_error;
                vel_msg.linear.x = 0.0;
            } else {
                if (distance > distance_tol_) {
                    // Move towards the spawn point
                    vel_msg.linear.x = std::min(distance * 0.5f, 1.0f);  // Scale linear speed
                    vel_msg.angular.z = 0.0;
                } else {
                    // Stop at the spawn point
                    vel_msg.linear.x = 0.0;
                    vel_msg.angular.z = 0.0;
                    state_ = "done";
                    RCLCPP_INFO(this->get_logger(), "Goal reached! D is completed.");
                }
            }
        }

        publisher_->publish(vel_msg);
    }

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
    rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr subscriber_;

    turtlesim::msg::Pose pose_;
    float radius_, angular_speed_, linear_speed_;
    float spawn_x_ = 0.0, spawn_y_ = 0.0, start_theta_ = 0.0;
    float target_angle_, angle_covered_;
    float distance_tol_;

    std::string state_;
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);

    
    float radius = std::stof(argv[1]);
    float angular_speed = std::stof(argv[2]);

    rclcpp::spin(std::make_shared<DrawLetterD>(radius, angular_speed));

    rclcpp::shutdown();
    return 0;
}
