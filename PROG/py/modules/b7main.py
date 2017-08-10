#!/usr/bin/env python
# encoding: utf-8
"""
b7 Playing with modules
Created by André Baumann on 2011-12-11.
Copyright (c) 2011 __MyCompanyName__. All rights reserved.
"""

from b7_utils import b7converter as conv
from b7_utils import b7vehicles as veh

'''
import b7_utils.b7converter
import b7_utils.b7vehicles
'''

def main():
	
	feet = conv.YardsToFeet(12)										# an ordinary module
	print str(feet) + ' feet'
	
	my_sedan = veh.Sedan('brown bruiser', 'brown')# a class module 
																								# instantiation
	print my_sedan.GetHorsePower()
	print my_sedan.GetNumDoors()
	
	
	class Honda(veh.Sedan):												# subclass to the Sedan class
	  def GetHorsePower(self):
	    return 'btw *120 - 160*'
	
	my_honda = Honda('rice rocket', 'green')
	print my_honda.GetNumDoors() 									# '4'
	print my_honda.GetHorsePower() 								# 'probably between 120 and 160'
	

if __name__ == '__main__':
	main()

