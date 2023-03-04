cmake_minimum_required(VERSION 3.8)
project(turtlebot3_wall)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()

include_directories(include)
ament_auto_add_library(${PROJECT_NAME} SHARED
 src/sub_laser.cpp include/${PROJECT_NAME}/sub_laser.hpp)

ament_auto_add_executable(sub_laser
  src/sub_laser.cpp
  src/sub_laser_node.cpp
)

# target_link_libraries(sub_laser)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_auto_package(INSTAL_TO_SHARE
  launch
  models
)

# ament_package()
