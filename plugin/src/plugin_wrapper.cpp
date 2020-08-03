#include <plugin/plugin_wrapper.h>


PluginWrapper::PluginWrapper(std::string module_name_, std::string class_name_)
: module_name(module_name_), class_name(class_name_)
{
    guard = new py::scoped_interpreter(); // start the interpreter and keep it alive
}

void PluginWrapper::run(){
    py::object Plugin = py::module::import(module_name.c_str()).attr(class_name.c_str());
    py::object plugin = Plugin();
    plugin.attr("run")();
}
