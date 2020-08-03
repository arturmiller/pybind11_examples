#include <iostream>

#include <pybind11/pybind11.h>

#include <classes/dog.h>


namespace py = pybind11;


Dog::Dog(const std::string &name) : name(name) { }

void Dog::bark() const { std::cout << "woof woof!" << std::endl; }

std::string Dog::getName() const { return name; }

void Dog::chase(const Cat &cat)
{
    bark();
    cat.meow();
}


PYBIND11_MODULE(dog, m) {
    py::class_<Dog>(m, "Dog")
        .def(py::init<const std::string &>())
        .def("bark", &Dog::bark, "Let the dog bark")
        .def("chase", &Dog::chase, "The dog chases a cat")
        .def_property_readonly("name", &Dog::getName, "The dog's name")
        .def("__repr__", [](const Dog &dog) {
            return "<Dog named '" + dog.getName() + "'>";
        });
}
