#!/usr/bin/env python
# encoding: utf-8
"""
Discription: dicts
Created by André Baumann 2012 Copyright (c) Google Inc. 2012. All rights reserved.
"""
import sys
from sys import exit
import os
	
def find_city(which_state, cities):
	if which_state in cities:
		return cities[which_state]
	else:
		return "Not found."

def main():
	cities = {'CA': 'San Francisco', 'MI': 'Detroit', 'FL': 'Jacksonville'}
	cities['NY'] = 'New York'
	cities['OR'] = 'Oregon'

	for key in cities:
		print key
		cities[key]()
		

	while True:
		print "State?: / ENTER to quit",
		which_state = raw_input("> ")
		if not which_state: break
		print find_city(which_state, cities)
								# simply calls find_city() with cities (the dict) 
								# and the state (entered), prints the return value

if __name__ == '__main__':
	main()
