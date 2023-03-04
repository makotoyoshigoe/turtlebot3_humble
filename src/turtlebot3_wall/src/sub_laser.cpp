#include"turtlebot3_wall/sub_laser.hpp"
#include<iostream>

namespace Turtlebot3Wall
{
    void SubLaser::scanCallback(const sensor_msgs::msg::LaserScan msg){
        ++scan_count;
        RCLCPP_INFO(get_logger(), "Subscribed count: %d", scan_count);
        // std::cout << scan_count << std::endl;
    }

    SubLaser::SubLaser()
    : Node("sub_laser"), count_(0)
    {
        scan_count = 0;
        initSubscription();
    }

    void SubLaser::initSubscription()
    {
        scan_subscription_ = this->create_subscription<sensor_msgs::msg::LaserScan>("scan", 10, std::bind(&SubLaser::scanCallback, this, std::placeholders::_1));
    }
}
