#ifndef __DOG_H__
#define __DOG_H__

#include <string>

#include <classes/cat.h>


class Dog {
public:
    Dog(const std::string &name);

    void bark() const;
    std::string getName() const;
    void chase(const Cat &cat);

private:
    std::string name;
};

#endif // __DOG_H__