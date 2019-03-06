#!/usr/bin/python2.4
# Copyright 2008 Google Inc. All Rights Reserved.

"""YearNames exercise unit test.

This unit test is written as a standard python test.
The google3 python tests will look very similar.

The test methods testGetYear() and testGetRank() are provided.
You can add tests for GetRanks() and GetSummaryText().
"""
__author__ = 'nparlante@google.com (Nick Parlante)'

import unittest
import yearnames


class YearNamesTest(unittest.TestCase):

  # setUp() can do common setup for the tests. Here we
  # construct a yearnames instance as self.yn
  def setUp(self):
    self.yn = yearnames.YearNames('yearnamestestdata.html')

  def testGetYear(self):
    self.assertEqual(1990, self.yn.GetYear())

  def testGetRank(self):
    self.assertEqual(1, self.yn.GetRank('Michael'))
    self.assertEqual(2, self.yn.GetRank('Ashley'))
    self.assertEqual(3, self.yn.GetRank('Matthew'))
    self.assertEqual(0, self.yn.GetRank('Notfound'))

  # +++your code here+++
  # You can add more tests.


if __name__ == '__main__':
  unittest.main()
