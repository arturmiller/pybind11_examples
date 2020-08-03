#include <pybind11/pybind11.h>

#include <plugin/base_plugin.h>


namespace py = pybind11;

class PyBasePlugin : public BasePlugin {
public:
    /* Inherit the constructors */
    using BasePlugin::BasePlugin;

    /* Trampoline (need one for each virtual function) */
    void run() override {
        PYBIND11_OVERLOAD_PURE(
            void,         /* Return type */
            BasePlugin,   /* Parent class */
            run,          /* Name of function in C++ (must match Python name) */
        );
    }
};

PYBIND11_MODULE(py_base_plugin, m) {
    py::class_<BasePlugin, PyBasePlugin>(m, "BasePlugin")
        .def(py::init<>())
        .def("run", &BasePlugin::run);
}
