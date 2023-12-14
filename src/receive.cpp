#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/header.hpp"

class Receive : public rclcpp::Node {
 public:
  Receive(std::string&& name) : Node(name) {
    RCLCPP_INFO(this->get_logger(), "This is Receive()");
    publisher_ = this->create_publisher<std_msgs::msg::Header>("from_receive", 10);
    subscription_ = this->create_subscription<std_msgs::msg::Header>(
        "from_send", 10,
        std::bind(&Receive::FeedbackCallback, this, std::placeholders::_1));
  }

 private:
  void FeedbackCallback(std_msgs::msg::Header::ConstSharedPtr msg) {
    this->publisher_->publish(*msg);
    RCLCPP_INFO(this->get_logger(), "receive a new msg");
  }
  rclcpp::Publisher<std_msgs::msg::Header>::SharedPtr publisher_;
  rclcpp::Subscription<std_msgs::msg::Header>::SharedPtr subscription_;
};

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<Receive>("receive");
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
