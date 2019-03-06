#!/usr/bin/env python
# encoding: utf-8
"""
write.py

Created by André Baumann on 2011-12-11.
Copyright (c) 2011 __MyCompanyName__. All rights reserved.
"""

import sys
import os


def main():
	
	write_str = 'Writing new stuff to file...'
	my_file = open('test.txt', 'a')			
	my_file.write(write_str)	

if __name__ == '__main__':
	main()

