#!/usr/bin/env python
# encoding: utf-8


'''
How to use classes and subclasses
- classes are templates

Created by André Baumann on 2011-12-11.
Copyright (c)2011 Google. All rights reserved.

'''

import sys
import os


class Dog(object):										# means Dog inherits from 'object'
	def __init__(self, name, breed):		# __init__ is class constructor method 
		self.name = name									# initilizing the instance vars
		self.breed = breed
		#print self.name + ' created this Dog instance'

	def Bark(self):											# classes also provide certain methods
		return 'barking!'

	def Greet(self):
		return 'Woof, I am ' + self.name

	def Rename(self, new_name):
		self.name = new_name
		return self.name
	
	def Owner(self, owner_id):
		self.owner = owner_id
		return 'Who owns '+ self.name +'? '+ self.owner +' does.'

class Puppy(Dog):									# creates a subclass of (now) superclass Dog
	def Bark(self):
		return 'Puppy wiff'
		
# --- lets play with this ---------------------------------------------------:

my_dog = Dog('Lou', 'Malti')			# - instantiate Dog object, calling the 
																	# contructor method. Ignore 1st var 'self'.
																	# - my_dog = Dog(breed='Malti', name='Lou') 												 

print my_dog.name 								# let'see this Dog's properties	
print my_dog.breed 								
																
print my_dog.Bark() 							# let's use this Dog's methods
print my_dog.Greet()

my_dog.Rename('Lou2')
print my_dog.Greet() 

print my_dog.Owner(u'André')			# this method adds an instance variable that 
																	# was not previously defined in the class.

# --- lets play with subclass -----------------------------------------------:

my_puppy = Puppy('Louchen', 'Malti')
print my_puppy.name 								
print my_puppy.breed

print my_puppy.Bark()							# uses the new bark method from subclass
  																# so subclasses EXTEND the superclass


						