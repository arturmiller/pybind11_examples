#!/usr/bin/env python

from py_base_plugin import BasePlugin


class CustomPlugin(BasePlugin):

    def __init__(self):
        BasePlugin.__init__(self)

    def run(self):
        print('hello world!')
