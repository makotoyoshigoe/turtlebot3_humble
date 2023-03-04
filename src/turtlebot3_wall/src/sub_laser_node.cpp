#include"turtlebot3_wall/sub_laser.hpp"

int main(int argc, char* argv[]){
    rclcpp::init(argc, argv);
    auto node = std::make_shared<Turtlebot3Wall::SubLaser>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}