cmake_minimum_required(VERSION 3.0.2)
project(function_call)

find_package(catkin REQUIRED COMPONENTS
    pybind11_catkin)

catkin_package(
    LIBRARIES
    CATKIN_DEPENDS pybind11_catkin
)

include_directories(${catkin_INCLUDE_DIRS})

pybind_add_module(logger MODULE src/logger.cpp)

catkin_install_python(PROGRAMS scripts/hello_world.py
                      DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

install(TARGETS logger
  LIBRARY DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
