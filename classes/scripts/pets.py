#!/usr/bin/env python
from cat import Cat
from dog import Dog



if __name__ == '__main__':
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
