#! /usr/bin/python

class Dog():
  def __init__(self,name,size):
    self.name = name
    self.size = size

  def Bark(self):
    return 'woof woof!' + 'I am a ' + self.size + ' sized dog'
	
  def Greet(self):
    return ' My name is ' + self.name + ' and I LOVE YOU'
