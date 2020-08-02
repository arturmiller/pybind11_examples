# pybind11_examples
[![Build Status](https://travis-ci.org/arturmiller/pybind11_examples.svg?branch=master)](https://travis-ci.org/arturmiller/pybind11_examples)

This repository shows minimal pybind11 using ROS. This project depends on [pybind11_catkin](https://github.com/ipab-slmc/pybind11_catkin). It is a [pybind11](https://github.com/pybind/pybind11) wrapper for ROS packages. Despite its name pybind11_catkin can be used in combination with catkin as well as with colcon.

## Installation
### Install prerequisites
This project depends on [pybind11_catkin](https://github.com/ipab-slmc/pybind11_catkin). You can install it with ```sudo apt-get install ros-<distro>-pybind11-catkin```. Depending on the ROS distribution ```<distro>``` is ```kinetic```, ```melodic``` or ```noetic```.

### Build with catkin tools
1. [Create a catkin workspace](https://catkin-tools.readthedocs.io/en/latest/quick_start.html#initializing-a-new-workspace) or use an existing workspace.
2. Clone this repository into the ```src/``` subdirectory of the workspace: ``git clone https://github.com/arturmiller/pybind11_examples.git``.
3. Compile the code ```catkin build```.
4. Source the config file: ```source path_to_workspace/devel/setup.bash```.

### Build with colcon
1. [Create a colcon workspace](https://index.ros.org/doc/ros2/Tutorials/Colcon-Tutorial/#create-a-workspace) or use an existing workspace.
2. Clone this repository into the ```src/``` subdirectory of the workspace: ``git clone https://github.com/arturmiller/pybind11_examples.git``.
3. Compile the code ```colcon build```.
4. Source the config file: ```source path_to_workspace/install/setup.bash```.

## Examples

### [Calling a C++ function](https://github.com/arturmiller/pybind11_examples/tree/master/function_call)
The first example is calling the C++ print function from Python.  
You run this example with ```rosrun function_call hello_world.py```. As output you should see ```hello world!```.

### [Basic classes usage](https://github.com/arturmiller/pybind11_examples/tree/master/classes)
The second example shows how to instantiate and use C++ classes in Python.

Run this example with ```rosrun classes pets.py```. This should be your output:
```
<Dog named 'Bello'>
Bello
woof woof!
woof woof!
meow!
```

### [Inheritance](https://github.com/arturmiller/pybind11_examples/tree/master/inheritance)
This example shows a Python class inheriting from a C++ class. A virtual C++ function is overriden in Python and called from the C++ base class.

Run it with ```rosrun inheritance dog.py```. You should see something similar to this:  
```
<__main__.Dog object at 0x7f90143954d0>
Fluffy dog Molly!
Fluffy dog Charly!
```

### [Plugin](https://github.com/arturmiller/pybind11_examples/tree/master/plugin)
The last two examples show, how to call C++ code in Python. This is can be very handy if you want to write a Python plugin system for a C++ library, as is the case for e.g. [Tensorflow](https://www.tensorflow.org/). There are multiple advantages of this approach. For example you can rerun the plugin without recompiling and running a debugger is much simpler Python.  
The following classes are part of the plugin system:
- [PluginRunner](https://github.com/arturmiller/pybind11_examples/blob/master/plugin/src/plugin_runner.cpp): The plugins are stored and called in this module.
- [BasePlugin](https://github.com/arturmiller/pybind11_examples/blob/master/plugin/src/base_plugin.cpp): All plugins inherit from BasePlugin.
- [CustomPlugin](https://github.com/arturmiller/pybind11_examples/blob/master/plugin/src/plugin/custom_plugin.py): A custom plugin implemented in Python.
- [PluginWrapper](https://github.com/arturmiller/pybind11_examples/blob/master/plugin/src/plugin_wrapper.cpp): The PluginWrapper calls the Python Plugin.
- [PyBasePlugin](https://github.com/arturmiller/pybind11_examples/blob/master/plugin/src/py_base_plugin.cpp): This module makes the base plugin accessible in Python.  

Run this example with ```rosrun plugin plugin_runner```. The Python plugin is called, with the resulting output ```hello world!```. Now you can change the string of the print statement and rerun it without recompiling the source code.
