cmake_minimum_required(VERSION 3.25)

project(waylandcpp-generator
        VERSION 0.1
        DESCRIPTION "C++ header generator from wayland xml specificaiton"
        LANGUAGES CXX)

add_subdirectory(libs/cpp)
add_subdirectory(src)
