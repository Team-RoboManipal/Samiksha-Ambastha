#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <iostream>
#include <thread>

using std::placeholders::_1;
using namespace std;

class ChatNode2 : public rclcpp::Node {
public:
    ChatNode2() : Node("chat_node_2") {
        publisher_ = this->create_publisher<std_msgs::msg::String>("chat_topic2", 10);
        subscription_ = this->create_subscription<std_msgs::msg::String>(
            "chat_topic1", 10, std::bind(&ChatNode2::message_callback, this, _1));

        input_thread_ = std::thread(&ChatNode2::send_messages, this);
    }

    ~ChatNode2() {
        if (input_thread_.joinable()) {
            input_thread_.join();
        }
    }

private:
    void message_callback(const std_msgs::msg::String::SharedPtr msg) {
        cout << "\n[Node 1]: " << msg->data << endl;
        cout << "[You]: ";
        cout.flush();
    }

    void send_messages() {
        while (rclcpp::ok()) {
            string input;
            cout << "[You]: ";
            getline(cin, input);

            auto message = std_msgs::msg::String();
            message.data = input;
            publisher_->publish(message);
        }
    }

    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
    std::thread input_thread_;
};

int main(int argc, char *argv[]) {
    rclcpp::init(argc, argv);
    auto node = std::make_shared<ChatNode2>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
