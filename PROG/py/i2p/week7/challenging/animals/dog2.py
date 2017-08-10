#! /usr/bin/python

import random

class Dog2():
	def __init__(self,name,size):
		self.name = name
		self.size = size
		right_sizes = ['small','medium','large']
		
		if self.size not in right_sizes:
			for x in range(5):
				y = raw_input('enter a size: ')
				if y in right_sizes:
					self.size = y
					break
				if x == 4:
					self.size = random.choice(right_sizes)
				
		
	def Bark(self):
		return 'woof woof!' + 'I am a ' + self.size + ' sized dog'
	
	def Greet(self):
		return ' My name is ' + self.name + ' and I LOVE YOU'
