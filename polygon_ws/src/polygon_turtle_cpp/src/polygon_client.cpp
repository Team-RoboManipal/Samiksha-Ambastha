#include <rclcpp/rclcpp.hpp>
#include "custom_interfaces/srv/polygon_server.hpp"
#include <iostream>
#include <cstdlib>

using namespace std::chrono_literals;

class DrawPolygonClient : public rclcpp::Node
{
public:
    DrawPolygonClient()
        : Node("draw_polygon_client")
    {
        client_ = this->create_client<custom_interfaces::srv::PolygonServer>("draw_polygon");
    }

    void send_request(int sides, double side_length)
    {
        auto request = std::make_shared<custom_interfaces::srv::PolygonServer::Request>();
        request->sides = sides;
        request->side_length = side_length;

        
        while (!client_->wait_for_service(1s))
        {
            RCLCPP_INFO(this->get_logger(), "Service not available, waiting again...");
        }

        
        client_->async_send_request(request, std::bind(&DrawPolygonClient::callback, this, std::placeholders::_1));
    }

private:
    void callback(rclcpp::Client<custom_interfaces::srv::PolygonServer>::SharedFuture future)
    {
        auto response = future.get();
        RCLCPP_INFO(this->get_logger(), "Response: Success=%d, Message: %s", response->success, response->message.c_str());
    }

    rclcpp::Client<custom_interfaces::srv::PolygonServer>::SharedPtr client_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    
    if (argc != 3)
    {
        std::cerr << "Usage: ros2 run polygon_turtle draw_client <sides> <side_length>\n";
        return 1;
    }

    int sides = std::stoi(argv[1]);
    double side_length = std::stod(argv[2]);

   
    auto client = std::make_shared<DrawPolygonClient>();
    client->send_request(sides, side_length);

    rclcpp::spin(client);  

    rclcpp::shutdown();
    return 0;
}

