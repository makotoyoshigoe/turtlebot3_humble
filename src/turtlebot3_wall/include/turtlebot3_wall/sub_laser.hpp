#include<rclcpp/rclcpp.hpp>
#include<sensor_msgs/msg/laser_scan.hpp>

namespace Turtlebot3Wall
{
    class SubLaser : public rclcpp::Node
    {
        public:
            explicit SubLaser();
        
        protected:
            void scanCallback(const sensor_msgs::msg::LaserScan msg);
            void initSubscription();

        private:
            size_t count_;
            rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr scan_subscription_;
            
            std::string namespace_;
            int scan_count;
    };
}
