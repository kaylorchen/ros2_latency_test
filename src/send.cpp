#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/header.hpp"

class Send : public rclcpp::Node {
 public:
  Send(std::string&& name) : Node(name) {
    RCLCPP_INFO(this->get_logger(), "This is Send()");
    publisher_ = this->create_publisher<std_msgs::msg::Header>("from_send", 10);
    auto send_callback = [this]() {
      std_msgs::msg::Header msg;
      msg.stamp = this->now();
      publisher_->publish(msg);
      RCLCPP_INFO(this->get_logger(), "publish a new msg");
    };
    timer_ = this->create_wall_timer(std::chrono::seconds(1), send_callback);
    subscription_ = this->create_subscription<std_msgs::msg::Header>(
        "from_receive", 10,
        std::bind(&Send::FeedbackCallback, this, std::placeholders::_1));
  }

 private:
  void FeedbackCallback(std_msgs::msg::Header::ConstSharedPtr msg) {
    auto now = this->now();
    auto duration = now - msg->stamp;
    RCLCPP_INFO(this->get_logger(), "duration is %fms",
                duration.nanoseconds() / 1000000.0);
  }
  rclcpp::Publisher<std_msgs::msg::Header>::SharedPtr publisher_;
  rclcpp::Subscription<std_msgs::msg::Header>::SharedPtr subscription_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared<Send>("send");
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}
