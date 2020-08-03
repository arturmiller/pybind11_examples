#include <pybind11/pybind11.h>

#include <inheritance/pet.h>


Pet::Pet(const std::string &name) : name(name) { }

void Pet::setName(const std::string &name) { this->name = name; }

std::string Pet::getName() { return decorateName(name); }


namespace py = pybind11;

class PyPet : public Pet {
public:
    /* Inherit the constructors */
    using Pet::Pet;

    /* Trampoline (need one for each virtual function) */
    std::string decorateName(std::string name) override {
        PYBIND11_OVERLOAD_PURE(
            std::string,  /* Return type */
            Pet,          /* Parent class */
            decorateName, /* Name of function in C++ (must match Python name) */
            name          /* Argument(s) */
        );
    }
};

PYBIND11_MODULE(pet, m) {
    py::class_<Pet, PyPet>(m, "Pet")
        .def(py::init<const std::string &>())
        .def("setName", &Pet::setName)
        .def("getName", &Pet::getName)
        .def("decorateName", &Pet::decorateName);
}
