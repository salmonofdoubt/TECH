#!/usr/bin/env python
# encoding: utf-8
'''
How to use classes and subclasses
Created by André Baumann on 2011-12-11.
Copyright (c)2011 Google. All rights reserved.
'''

import sys
import os

class Cat(object):										# classes are templates®
	def __init__(self, name, fur_color, temper):
																			# __init__ is class constructor method 
		self.name = name									# initilizing the instance vars
		self.fur_color = fur_color
		self.temper = temper


	def Purr(self):											# classes also provide certain methods
		return 'purrr!'

	def GetTemper(self):
		temper = int(raw_input('> Temper scale 1..10, default is 5: '))
		if temper >= 5:
			print 'That\'s a really angry cat, needs mellowing measures..'
			overtemper = int(temper) - 5
			my_cat.MellowOut(overtemper)
			return 'Was angry'
		elif (temper >= 2 and temper < 5):
			return 'Pretty normal cat now'
		elif temper < 2:
			return 'Mellow Cat'
		else:
			return None

	def MellowOut(self, reducing):
		self.temper = self.temper - reducing 
		print 'Mellowing Garfield out by ' + str(reducing)
		return self.temper
		
# --- lets play with this ---------------------------------------------------:
my_cat = Cat('Garfield', 'Orange', 5)	# instantiate Cat object, calling the
																			# contructor method. Ignore 1st var
																			# 'self'.
																	
print my_cat.name 								# let'see this Cat's properties	
print my_cat.fur_color 								
print my_cat.Purr() 							# let's use this Cat's methods

print my_cat.GetTemper()					# original property





