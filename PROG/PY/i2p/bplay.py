#!/usr/bin/env python
# encoding: utf-8
"""
bplay.py

Created by André Baumann on 2011-12-11.
Copyright (c) 2011 __MyCompanyName__. All rights reserved.
"""

import sys
import os


def main():
	my_list = ['john', 'pat', 'gary', 'michael']
	for i, name in enumerate(my_list):
		print "iteration %i is %s" % (i, name)

	parents, babies = (1, 1)
	while babies < 100:
		print 'This generation has %d babies' % babies, parents, babies = (babies, parents + babies)

if __name__ == '__main__':
	main()

