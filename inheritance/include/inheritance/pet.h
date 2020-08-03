#ifndef __PET_H__
#define __PET_H__

#include <string>


class Pet {
public:
    Pet(const std::string &name);
    virtual std::string decorateName(const std::string name) = 0;
    void setName(const std::string &name);
    std::string getName();

private:
    std::string name;
};

#endif // __PET_H__