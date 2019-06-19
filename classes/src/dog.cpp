#include <iostream>
#include <string>

#include <pybind11/pybind11.h>


namespace py = pybind11;


class Cat {
public:
    void meow() const {std::cout << "meow!" << std::endl; }    
};


class Dog {
public:
    Dog(const std::string &name) : name(name) { }

    void bark() const { std::cout << "woof woof!" << std::endl; }
    std::string getName() const { return name; }
    void chase(const Cat &cat)
    {
        bark();
        cat.meow();
    }

private:
    std::string name;
};



PYBIND11_MODULE(dog, m) {
    py::class_<Cat>(m, "Cat")
        .def(py::init<>());

    py::class_<Dog>(m, "Dog")
        .def(py::init<const std::string &>())
        .def("bark", &Dog::bark, "Let the dog bark")
        .def("chase", &Dog::chase, "The dog chases a cat")
        .def_property_readonly("name", &Dog::getName, "The dog's name")
        .def("__repr__", [](const Dog &dog) {
            return "<Dog named '" + dog.getName() + "'>";
        });
}
