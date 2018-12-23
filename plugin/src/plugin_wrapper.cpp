#include <string>

#include <pybind11/pybind11.h>
#include <pybind11/embed.h>

#include "base_plugin.cpp"


namespace py = pybind11;

class PluginWrapper : public BasePlugin{
public:
    PluginWrapper(std::string module_name_, std::string class_name_)
    : module_name(module_name_), class_name(class_name_)
    {
        guard = new py::scoped_interpreter(); // start the interpreter and keep it alive
    }

    void run(){
        py::object Plugin = py::module::import(module_name.c_str()).attr(class_name.c_str());
        py::object plugin = Plugin();
        plugin.attr("run")();
    }

private:
    py::scoped_interpreter *guard;
    std::string module_name;
    std::string class_name;
};

