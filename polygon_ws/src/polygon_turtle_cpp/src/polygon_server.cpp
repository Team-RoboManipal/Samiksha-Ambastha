#include "rclcpp/rclcpp.hpp"
#include "custom_interfaces/srv/polygon_server.hpp"
#include <geometry_msgs/msg/twist.hpp>
#include <turtlesim/msg/pose.hpp>
#include <cmath>
#include <chrono>
using namespace std::chrono_literals; 

class DrawPolygonServer : public rclcpp::Node
{
public:
    DrawPolygonServer()
        : Node("draw_polygon_server"),
          state_("idle"), sides_(0), side_length_(0.0), linear_speed_(0.5),
          target_angle_increment_(0.0), target_angle_(0.0), sides_drawn_(0),
          spawn_x_(0.0), spawn_y_(0.0)
    {
        publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("turtle1/cmd_vel", 10);
        subscriber_ = this->create_subscription<turtlesim::msg::Pose>(
            "turtle1/pose", 10, std::bind(&DrawPolygonServer::pose_callback, this, std::placeholders::_1));

        service_ = this->create_service<custom_interfaces::srv::PolygonServer>(
            "draw_polygon", std::bind(&DrawPolygonServer::handle_polygon_request, this, std::placeholders::_1, std::placeholders::_2));

        timer_ = this->create_wall_timer(100ms, std::bind(&DrawPolygonServer::control_loop, this));
    }

private:
    void pose_callback(const turtlesim::msg::Pose::SharedPtr msg)
    {
        pose_ = msg;
    }

    void handle_polygon_request(const custom_interfaces::srv::PolygonServer::Request::SharedPtr request,
                                 custom_interfaces::srv::PolygonServer::Response::SharedPtr response)
    {
        sides_ = request->sides;
        side_length_ = request->side_length;
        linear_speed_ = std::min(0.5, side_length_ / 2);
        target_angle_increment_ = 2 * M_PI / sides_;

        state_ = "start";
        sides_drawn_ = 0;
        spawn_x_ = 0.0;
        spawn_y_ = 0.0;

        RCLCPP_INFO(this->get_logger(), "Received request: %d sides, %f side length", sides_, side_length_);

        response->success = true;
        response->message = "Polygon drawing started.";
    }

    void control_loop()
    {
        if (!pose_)
            return;

        geometry_msgs::msg::Twist vel_msg;

        if (state_ == "start" && spawn_x_ == 0.0 && spawn_y_ == 0.0)
        {
            spawn_x_ = pose_->x;
            spawn_y_ = pose_->y;
            target_angle_ = pose_->theta;
            state_ = "draw_polygon";
        }

        if (state_ == "draw_polygon")
        {
            double distance = std::sqrt(std::pow(pose_->x - spawn_x_, 2) + std::pow(pose_->y - spawn_y_, 2));
            vel_msg.linear.x = linear_speed_;

            if (distance >= side_length_)
            {
                vel_msg.linear.x = 0.0;
                sides_drawn_++;

                if (sides_drawn_ >= sides_)
                {
                    state_ = "done";
                }
                else
                {
                    state_ = "rotate";
                    spawn_x_ = pose_->x;
                    spawn_y_ = pose_->y;
                    target_angle_ += target_angle_increment_;
                }
            }
            publisher_->publish(vel_msg);
        }
        else if (state_ == "rotate")
        {
            double angle_error = target_angle_ - pose_->theta;
            angle_error = std::atan2(std::sin(target_angle_ - pose_->theta), std::cos(target_angle_ - pose_->theta));

            if (std::abs(angle_error) < 0.1)
            {
                vel_msg.angular.z = 0.0;
                state_ = "draw_polygon";
            }
            else
            {
                double angular_speed = 2.0;
                vel_msg.angular.z = (angle_error > 0) ? angular_speed : -angular_speed;
            }

            publisher_->publish(vel_msg);
        }
        else if (state_ == "done")
        {
            vel_msg.linear.x = 0.0;
            vel_msg.angular.z = 0.0;
            publisher_->publish(vel_msg);
        }
    }

    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
    rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr subscriber_;
    rclcpp::Service<custom_interfaces::srv::PolygonServer>::SharedPtr service_;
    rclcpp::TimerBase::SharedPtr timer_;

    turtlesim::msg::Pose::SharedPtr pose_;
    std::string state_;
    int sides_;
    double side_length_;
    double linear_speed_;
    double target_angle_increment_;
    double target_angle_;
    int sides_drawn_;
    double spawn_x_;
    double spawn_y_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<DrawPolygonServer>());
    rclcpp::shutdown();
    return 0;
}

