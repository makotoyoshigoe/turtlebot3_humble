#include<rclcpp/rclcpp.hpp>
#include<rclcpp/qos.hpp>
#include<sensor_msgs/msg/laser_scan.hpp>
#include<iostream>

void scan_callback(const sensor_msgs::msg::LaserScan msg){
    std::cout << "subscribe scan" << std::endl;
}

int main(int argc, char* argv[]){
    rclcpp::init(argc, argv);

    auto node = rclcpp::Node::make_shared("sub_laser");
    auto scan_subscription = node->create_subscription<sensor_msgs::msg::LaserScan>("scan", rclcpp::QoS(10), std::bind(scan_callback, std::placeholders::_1));

    rclcpp::spin(node);
    rclcpp::shutdown();

    node = nullptr;
    return 0;
}