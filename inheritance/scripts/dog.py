#!/usr/bin/env python

from pet import Pet


class Dog(Pet):

    def __init__(self, name):
        Pet.__init__(self, name)

    def decorateName(self, name):
        return 'Fluffy dog ' + name + '!'


if __name__ == '__main__':
    pet = Dog('Molly')
    print(pet)
    print(pet.getName())
    pet.setName('Charly')
    print(pet.getName())
