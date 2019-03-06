#!/usr/bin/env python
# encoding: utf-8
"""
url.py

Created by André Baumann on 2011-12-13.
Copyright (c) 2011 Google. All rights reserved.
"""

import sys
import os
import urllib

class SuperUrl(object):				# means SuperURL inherits from 'object'
	def __init__(self, name):		# __init__ is class constructor method 
		self.name = name					# initilizing the instance vars




	def UrlToText(self, url): #2
		url_file = urllib.urlopen(url) #3
		contents = url_file.read() #4
		return contents


	def GetUrl(self):
		Url = raw_input('Enter URL: ')
		contents = UrlToText(Url)
		SaveToDestination(contents)


	def SaveToDestination(self, contents):
		my_file = open('/Users/abaumann/Downloads/content.txt', 'a')
		my_file.write(contents)
		my_file.write('\n\n* * *\n\n')


instance = SuperUrl('Test')		# - instantiate SuperUrl object, calling its
															# contructor method. Ignore 1st var 'self'.
instance.GetUrl()

