#!/usr/bin/env python

from example import add


if __name__ == '__main__':
    res = add(5, 3) # here the C++ function is called
    print('hello world, 5 + 3 = {}'.format(res))
