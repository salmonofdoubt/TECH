#!/usr/bin/env python
# encoding: utf-8
"""
Discription: 
Created by André Baumann 2012 Copyright (c) Google Inc. 2012. All rights reserved.
"""

class TheThing(object):			# TheThing inherits from object
	
	def __init__(self):				# __init__ is the class's constructor method
		self.number = 3					# initializes the instance's variables

	def printo(self):
		print "printo got called."

	def addo(self, more):
		print self.number
		self.number += more			# will use number 3 
		print self.number

a = TheThing()							# classes, just like methods can be variables

a.printo()									# of class a (TheThing), call printo
a.addo(10)									# of class a, call addo and pass it a value 
a.addo(10)

def main():
	pass
if __name__ == '__main__':
	main()
