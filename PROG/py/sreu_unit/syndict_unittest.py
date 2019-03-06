#!/usr/bin/env python
# encoding: utf-8
"""
syndict_test.py
Created by André Baumann on 2011-12-16.
Copyright (c) 2011 __MyCompanyName__. All rights reserved.
"""

import syndict
import unittest
import sys
import os

class SyndictTest(unittest.TestCase):
	def setUp(self):
		self.d = syndict.SynonymDict()	#use this in each fct instead

	def testIsInitialized(self):			#data must have been loaded
		d = syndict.SynonymDict()
		d.LoadDictionary('syn-good1.txt')
		d.IsInitialized()
		#self.assertEquals(True, d.IsInitialized())
		self.assertTrue(d.IsInitialized())

	def testLoadDictionary(self):
		d = syndict.SynonymDict()
		self.assertFalse(d.IsInitialized())

"""
	def testInitilizeFalse(self):
		d = syndict.SynonymDict()
		d.LoadDictionary('syn-good1.txt')
		d.IsInitialized()
		self.assertFalse(d.IsInitialized())
"""

if __name__ == '__main__':
	unittest.main()
