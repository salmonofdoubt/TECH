#!/usr/bin/env python
# encoding: utf-8
"""
Discription: 
Created by André Baumann 2012 Copyright (c) Google Inc. 2012. All rights reserved.
"""
import sys
import os

def data_input():
	people = raw_input('> How many people?: ')
	cars = raw_input('> How many cars?: ')
	buses = raw_input('> How many buses?: ')
	
	return people, cars, buses

def main():
	
	people, cars, buses = data_input()

	if cars > people:
		print "1.Take cars"
	elif cars < people:
		print "1.Dont take cars"
	else:
		print "1.Can't decide"
		
	if buses > cars:
		print "2.Too many buses"
	elif buses < cars:
		print "2.Take buses"
	else: 
		print "2.Can't decide"
		
	if people > buses:
		print "3.Take buses"
	elif people < buses:
		print "3.Take one bus"
	else: "3.Can't decide"

if __name__ == '__main__':
	main()
