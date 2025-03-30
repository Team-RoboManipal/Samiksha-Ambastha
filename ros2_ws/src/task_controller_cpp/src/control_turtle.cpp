#include <memory>
#include <functional>
#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "turtlesim/msg/pose.hpp"
#include <cmath>
#include <cstdlib>
#include <chrono>

using namespace std::chrono_literals;

class GoToGoal : public rclcpp::Node {
public:
  GoToGoal(float goal_x, float goal_y)
  : Node("goal_node"), goal_x_(goal_x), goal_y_(goal_y) {
    publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("turtle1/cmd_vel", 10);
    subscriber_ = this->create_subscription<turtlesim::msg::Pose>("turtle1/pose", 10, std::bind(&GoToGoal::pose_callback, this, std::placeholders::_1));
    timer_ = this->create_wall_timer(500ms, std::bind(&GoToGoal::go_to_goal, this));
  }

private:
  void pose_callback(const turtlesim::msg::Pose::SharedPtr msg) {
    pose_ = *msg;
  }

  void go_to_goal() {
    geometry_msgs::msg::Twist new_vel;
    
    // Calculate distance to the goal
    float distance = std::sqrt(std::pow(goal_x_ - pose_.x, 2) + std::pow(goal_y_ - pose_.y, 2));
    
    // Calculate the angle to the goal
    float theta = std::atan2(goal_y_ - pose_.y, goal_x_ - pose_.x);
    
    // Calculate the angle error
    float angle_error = theta - pose_.theta;
    if (angle_error > M_PI) {
      angle_error -= 2 * M_PI;
    } else if (angle_error < -M_PI) {
      angle_error += 2 * M_PI;
    }

    // Set tolerances for distance and angle
    float distance_tol = 0.3;
    float angle_tol = 0.1;

    if (std::abs(angle_error) > angle_tol) {
      // Rotate the turtle to face the goal
      new_vel.angular.z = 0.5 * angle_error; // Use a constant angular velocity
      new_vel.linear.x = 0.0;
    } else {
      if (distance > distance_tol) {
        // Move forward towards the goal
        new_vel.linear.x = 1.0 * distance; // Use a constant linear speed
        new_vel.angular.z = 0.0;
      } else {
        // Goal reached
        new_vel.linear.x = 0.0;
        new_vel.angular.z = 0.0;
        RCLCPP_INFO(this->get_logger(), "Goal reached!");
        rclcpp::shutdown();
      }
    }

    RCLCPP_INFO(this->get_logger(), "Distance to goal: %.3f, Angle error: %.3f", distance, angle_error);
    publisher_->publish(new_vel);
  }

  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
  rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr subscriber_;
  turtlesim::msg::Pose pose_;
  float goal_x_, goal_y_;
};

int main(int argc, char *argv[]) {
  rclcpp::init(argc, argv);
  float goal_x = std::stof(argv[1]);
  float goal_y = std::stof(argv[2]);

  rclcpp::spin(std::make_shared<GoToGoal>(goal_x, goal_y));
  rclcpp::shutdown();
  return 0;
}
