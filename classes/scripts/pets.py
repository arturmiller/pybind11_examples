#!/usr/bin/env python

from dog import Dog, Cat
#import pdb
#pdb.set_trace()
#/home/amiller/workspace/devel/lib/python3/dist-packages/dog.cpython-38-x86_64-linux-gnu.so
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
