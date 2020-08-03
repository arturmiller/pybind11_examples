cmake_minimum_required(VERSION 3.0.2)
project(classes)

find_package(catkin REQUIRED COMPONENTS
    pybind11_catkin)

catkin_package(
    LIBRARIES
    CATKIN_DEPENDS pybind11_catkin
)

include_directories(${PROJECT_SOURCE_DIR}/include
                    ${catkin_INCLUDE_DIRS})


pybind_add_module(dog MODULE src/dog.cpp src/cat.cpp)
pybind_add_module(cat SHARED src/cat.cpp)

catkin_install_python(PROGRAMS scripts/pets.py
                      DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

install(TARGETS dog
                cat
  LIBRARY DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
