#ifndef __PLUGIN_WRAPPER_H__
#define __PLUGIN_WRAPPER_H__

#include <string>

#include <pybind11/pybind11.h>
#include <pybind11/embed.h>

#include <plugin/base_plugin.h>


namespace py = pybind11;

class PluginWrapper : public BasePlugin{
public:
    PluginWrapper(std::string module_name_, std::string class_name_);

    void run();

private:
    py::scoped_interpreter *guard;
    std::string module_name;
    std::string class_name;
};


#endif // __PLUGIN_WRAPPER_H__