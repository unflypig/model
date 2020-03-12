#cmake 最小版本要求
cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_FLAGS "-pthread ${CMAKE_CXX_FLAGS}")
#项目名称
project(gtest_demo)
set(PROJECT_ROOT_PATH ${PROJECT_SOURCE_DIR})
#添加头文件路径
include_directories(./inc)
#生成库文件的CMakeLists.txt存放目录
#add_subdirectory(./my_lib)
#生成可执行文件文件的CMakeLists.txt存放目录
add_subdirectory(./src)
