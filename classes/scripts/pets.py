#!/usr/bin/env python

from dog import Dog, Cat


if __name__ == '__main__':
    help(Dog)

    dog = Dog('Bello')
    print(dog)
    # <Dog named 'Bello'>

    print(dog.name)
    # Bello

    dog.bark()
    # woof woof!

    cat = Cat()
    dog.chase(cat)
    # woof woof!
    # meow!
