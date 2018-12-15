cmake_minimum_required(VERSION 2.8.3)
project(pybind11_example)

find_package(catkin REQUIRED COMPONENTS
    pybind11_catkin)

catkin_package(
    LIBRARIES
    CATKIN_DEPENDS pybind11_catkin
)

include_directories(${catkin_INCLUDE_DIRS})

pybind_add_module(logger MODULE src/logger.cpp)
