# pybind11_example
This repository shows a minimal pybind11 example using catkin. The C++ add function in src/example.cpp is called by the Python module hello_world.py. This project depends on [pybind11_catkin](https://github.com/ipab-slmc/pybind11_catkin). It is a [pybind11](https://github.com/pybind/pybind11) catkin package. Having a catkin package is very convenient if you are using catkin as build system.

## Installation
1. [Create a catkin workspace](https://catkin-tools.readthedocs.io/en/latest/quick_start.html#initializing-a-new-workspace) or use an existing workspace.
2. Clone this repository into the ```src/``` subdirectory of the workspace: ``git clone https://github.com/arturmiller/pybind11_example.git``.
3. Clone the project [pybind11_catkin](https://github.com/ipab-slmc/pybind11_catkin) int the ```src/``` subdirectory: ``git clone https://github.com/ipab-slmc/pybind11_catkin``. 
4. Compile the code ```catkin build pybind11_example```.
5. Source the config file: ```source path_to_workspace/devel/setup.bash```.

## Run the example
You run this example with ```rosrun pybind11_example hello_world.py```. As output you should see ```hello world, 5 + 3 = 8```.
