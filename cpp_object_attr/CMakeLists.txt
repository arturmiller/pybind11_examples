cmake_minimum_required(VERSION 2.8.3)
project(cpp_object_attr)

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

find_package(catkin REQUIRED COMPONENTS
    pybind11_catkin)

catkin_python_setup()

catkin_package(
    LIBRARIES
    CATKIN_DEPENDS pybind11_catkin
)

pybind_add_module(cpp_object MODULE src/cpp_object.cpp)
pybind_add_module(example SHARED src/example.cpp )
add_executable(main src/main.cpp)
target_link_libraries(main ${PYTHON_LIBRARIES} example)
