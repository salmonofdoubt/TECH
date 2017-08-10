#!/usr/bin/env python
# encoding: utf-8
"""
Created by André Baumann on 2011-08-23.
Copyright (c) Google Inc. 2011. All rights reserved.
"""
import sys
import os

def main():
	value = 'smith'
	time = 'midday'	
	#call current exercise:
	
	print yawn(time)
	
	dict_ex()
	
	tuple_ex(value)
	range_ex()
	print list_ex4()
	list_ex3()
	list_ex2(value)
	list_ex1(value) 

	
	#call prev exercises:
	even()
	remain(36)
	exercise()
	
def yawn(time_of_day):
	yawn_txt = 'Ah...'+ time_of_day +'.'
	return yawn_txt 
	
	
def dict_ex():
	#key:value
	mydict = {'bugs': 'rabbit',
	          'elmer': 'human',
	          'wiley': 'coyote',
	          'tomas': 'cat',
	          'jerry': 'mouse'}
	
	print mydict['elmer']
	del mydict['elmer']
	
	for k in mydict:
		print k
		
	None
	
def tuple_ex(value):
	mytuple = ('andre','c','baumann')
	#nothing tbd here...

	
def range_ex():
	#range(<start_int>, <end_int>, <interval>)
	mylist = ['andre','c','baumann']
	print '------\n'
	
	for i in range(len(mylist),-2 ,-1):
		print str(i)
	
	for i in range(0, len(mylist), 2):
		mylist[i] = mylist[i].upper()
	
	for i in mylist:
		print i.split()
	
	print mylist
	
	for i in mylist:
		if 'ANDRE' in i:
			print i, 'test ok'
  	
	print '------\n'
	
	numbers = range(5,0,-1)
	for num in numbers:
		print str(num) + ' bottles of beers...'
		
	print '------\n'
	


def list_ex4():
	mylist = ['andre','c','baumann']
	count = 0
	for i in mylist:
		mylist[count] = i.upper()
		count += 1	 
	return 'listex4: ', mylist

def list_ex3():
	mylist = ['andre','c','baumann']
	for element in mylist:
		print 'listex3: ', 'items in order :', element
			

def list_ex2(value):
	mylist = ['andre','c','baumann']
	mylist.sort() #outplace sort: sorted(), inplace sort: mylist.sort() 
	print 'listex2: ', mylist

					
def list_ex1(value):
	mylist = ['andre','c','baumann']
	mylist.append(value)
	print 'listex1: ', len(mylist), mylist[3][2]
	

	



def even():
	print '------\n'
	
	x = 'xxx'
	while x: 
		print x
		x = x[1:]  
	print '------\n'

	x = 8
	while x:
		x -= 1
		if x % 2 != 0: continue #prints all even numbers
		print x

	print '------\n'

	
def remain(y):
	x = y / 2
	while x > 1:
		if y % x == 0: # remainder
			print y, 'has factor', x, '\n'
			break # skip else
			x = x-1
		else: # normal exit
			print y, 'is prime \n'
			sys.exit(0)
			
			
def exercise():
	count = 4
	number = 'number:'
	text = ['pos 1', 
					'pos 2',
					'pos 3',
					'pos 4'] 
	
	while count > 0:
		for i in range(len(text)):
			print number, count, text[i]
			count -= 1
		

if __name__ == '__main__':
 	main()

