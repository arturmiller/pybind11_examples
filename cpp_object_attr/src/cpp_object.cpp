#include <pybind11/pybind11.h>

namespace py = pybind11;


class CppObject{
public:
    CppObject(){}
};


PYBIND11_MODULE(cpp_object, m) {
    py::class_<CppObject>(m, "CppObject")
        .def(py::init<>());
}
