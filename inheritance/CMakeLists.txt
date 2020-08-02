cmake_minimum_required(VERSION 3.0.2)
project(inheritance)

find_package(catkin REQUIRED COMPONENTS
    pybind11_catkin)

catkin_package(
    LIBRARIES
    CATKIN_DEPENDS pybind11_catkin
)

include_directories(${catkin_INCLUDE_DIRS})

pybind_add_module(pet MODULE src/pet.cpp)

catkin_install_python(PROGRAMS scripts/dog.py
                      DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

install(TARGETS pet
  LIBRARY DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
