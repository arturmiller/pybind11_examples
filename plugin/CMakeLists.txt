cmake_minimum_required(VERSION 3.0.2)
project(plugin)
add_compile_options(-Wno-attributes -std=c++11)

find_package(PythonLibs REQUIRED)

find_package(catkin REQUIRED COMPONENTS
    pybind11_catkin)

catkin_python_setup()

catkin_package(
    LIBRARIES
    CATKIN_DEPENDS pybind11_catkin
)

include_directories(${PROJECT_SOURCE_DIR}/include
                    ${PYTHON_INCLUDE_DIRS}
                    ${catkin_INCLUDE_DIRS})

add_library(base_plugin SHARED src/base_plugin.cpp)
add_library(plugin_wrapper SHARED src/plugin_wrapper.cpp)
target_link_libraries(plugin_wrapper ${PYTHON_LIBRARIES} base_plugin)

pybind_add_module(py_base_plugin MODULE src/py_base_plugin.cpp)

add_executable(plugin_runner src/plugin_runner.cpp)
target_link_libraries(plugin_runner ${PYTHON_LIBRARIES} base_plugin plugin_wrapper)

install(TARGETS plugin_runner
                base_plugin
                plugin_wrapper
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(TARGETS py_base_plugin
  LIBRARY DESTINATION ${PYTHON_INSTALL_DIR}
)
