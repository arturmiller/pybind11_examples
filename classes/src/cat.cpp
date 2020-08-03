#include <iostream>
#include <string>

#include <pybind11/pybind11.h>

#include <classes/cat.h>


namespace py = pybind11;


void Cat::meow() const {std::cout << "meow!" << std::endl; } 


PYBIND11_MODULE(cat, m) {
    py::class_<Cat>(m, "Cat")
        .def(py::init<>());
}
