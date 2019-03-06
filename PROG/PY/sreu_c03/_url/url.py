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


def UrlToText(url): #2
	url_file = urllib.urlopen(url) #3
	contents = url_file.read() #4
	return contents

def GetUrl():
	Url = raw_input('Enter URL: ')
	contents = UrlToText(Url)
	SaveToDestination(contents)

def SaveToDestination(contents):
	my_file = open('/Users/abaumann/Downloads/content.txt', 'a')
	my_file.write(contents)
	my_file.write('\n\n* * *\n\n')
	
	
def main():
	GetUrl()
	

if __name__ == '__main__':
  main()