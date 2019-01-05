#include <pybind11/embed.h>

#include "cpp_object.cpp"


namespace py = pybind11;

void example()
{
    py::scoped_interpreter guard{};

    py::module::import("cpp_object").attr("CppObject");
    py::object print_type = py::module::import("cpp_object_attr.type_printer").attr("print_type");
    CppObject cpp_object;
    print_type(cpp_object);
}
