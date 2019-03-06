#!/usr/bin/python2.4
# Copyright 2008 Google Inc. All Rights Reserved.

"""
Simple example of a python unit test on the Quote class.
quotesimple_test.py
nparlante@google.com

Basically:
 -import unittest
 -subclass off TestCase
 -can have setUp() for common data for the tests
 -write testXXX methods
 -call self.assertEquals()
 -main() calls unittest.main()
 -run this file to run the tests
"""

import unittest
import quotesimple

class QuoteUnitTest(unittest.TestCase):  # Subclass off TestCase
  def setUp(self):
    # (optional) can do shared setup for tests in here
    self.something = 6

  def testBasic(self):  # Write test methods beginning with 'test'
    quote = quotesimple.Quote('text', 'author')
    self.assertEquals('text', quote.GetText())   # getter way
    self.assertEquals('author', quote.author)    # just access it way

  def testFormatted(self):
    quote = quotesimple.Quote('text', 'author')
    self.assertEquals('text\n--author\n', quote.GetFormatted())

if __name__ == '__main__':
  unittest.main()

