# pybind11_examples
This repository shows minimal pybind11 examples using catkin. This project depends on [pybind11_catkin](https://github.com/ipab-slmc/pybind11_catkin). It is a [pybind11](https://github.com/pybind/pybind11) catkin package. Having a catkin package is very convenient if you are using catkin as build system.

## Installation
1. Install the package [pybind11_catkin](https://github.com/ipab-slmc/pybind11_catkin) with ```sudo apt-get install ros-kinetic-pybind11-catkin```
2. [Create a catkin workspace](https://catkin-tools.readthedocs.io/en/latest/quick_start.html#initializing-a-new-workspace) or use an existing workspace.
3. Clone this repository into the ```src/``` subdirectory of the workspace: ``git clone https://github.com/arturmiller/pybind11_examples.git``.
4. Compile the code ```catkin build```.
5. Source the config file: ```source path_to_workspace/devel/setup.bash```.

## Examples

### Calling a C++ function
The first example is C++ print function, which is call in Python.
You run this example with ```rosrun function_call hello_world.py```. As output you should see ```hello world!```.

### Class inheritance
The second example shows a Python class inheriting from a C++ class. An in Python overriden method is called from the C++ base class.

Run it with ```rosrun inheritance dog.py```. You should see something similar to this:  
```
<__main__.Dog object at 0x7f90143954d0>
Fluffy dog Molly!
Fluffy dog Charly!
```

### Plugin
The last two examples have shown, how to call C++ code from Python. With Pybind11 you can do the inverse as well. This is needed for example if you want to write a plugin written in Python for a C++ library. There are multiple advantages of this approach. For example you can rerun the plugin without recompiling and running a debugger is much simpler.  
The following classes are part of the plugin system:
- [PluginRunner](https://github.com/arturmiller/pybind11_examples/blob/master/plugin/src/plugin_runner.cpp): The plugins are stored and called in this module.
- [BasePlugin](https://github.com/arturmiller/pybind11_examples/blob/master/plugin/src/base_plugin.cpp): All plugins inherit from BasePlugin.
- [CustomPlugin](https://github.com/arturmiller/pybind11_examples/blob/master/plugin/src/plugin/custom_plugin.py): A custom plugin implemented in Python.
- [PluginWrapper](https://github.com/arturmiller/pybind11_examples/blob/master/plugin/src/plugin_wrapper.cpp): The PluginWrapper calls the Python Plugin.
- [PyBasePlugin](https://github.com/arturmiller/pybind11_examples/blob/master/plugin/src/py_base_plugin.cpp): This module makes the base plugin accessible in Python.  

Run this example with ```rosrun plugin plugin_runner```. The Python plugin is called, with the resulting output ```hello world!```. Now you can change the string of the print statement and rerun it without recompiling the source code.
