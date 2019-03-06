#! /usr/bin/python

import random


class Dog2():
  def __init__(self,name,size):
    self.name = name
    self.size = size

  def Bark(self):
    return 'woof woof!' + 'I am a ' + self.size + ' sized dog'

  class Labrador2(Dog2):	
    def Greet(self):
      return 'My name is ' + self.name + ' and I LOVE YOU and LOVE to PLAY!'
