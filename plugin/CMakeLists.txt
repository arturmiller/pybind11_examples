cmake_minimum_required(VERSION 3.0.2)
project(plugin)

find_package(PythonLibs REQUIRED)

find_package(catkin REQUIRED COMPONENTS
    pybind11_catkin)

catkin_python_setup()

catkin_package(
    LIBRARIES
    CATKIN_DEPENDS pybind11_catkin
)

include_directories(${PYTHON_INCLUDE_DIRS} ${catkin_INCLUDE_DIRS})

add_library(base_plugin SHARED src/base_plugin.cpp)

pybind_add_module(py_base_plugin MODULE src/py_base_plugin.cpp)

pybind_add_module(plugin_wrapper SHARED src/plugin_wrapper.cpp )
add_executable(plugin_runner src/plugin_runner.cpp)
target_link_libraries(plugin_runner ${PYTHON_LIBRARIES} plugin_wrapper base_plugin)

install(TARGETS plugin_runner
                py_base_plugin
  LIBRARY DESTINATION ${PYTHON_INSTALL_DIR}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
