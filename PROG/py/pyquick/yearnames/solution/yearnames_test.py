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
    self.assertEqual(0, self.yn.GetRank('Notfound'))

  # +++your code here+++
  # You can add more tests.
  # LAB(begin solution)
  def testGetRanks(self):
    expected_ranks = [('Ashley', 2), ('Brittany', 3), ('Christopher', 2),
        ('Jessica', 1), ('Matthew', 3), ('Michael', 1)]
    self.assertEquals(expected_ranks, self.yn.GetRanks())

  def testSummaryText(self):
    expected_summary = (
        '1990\nAshley 2\nBrittany 3\nChristopher 2\n'
        'Jessica 1\nMatthew 3\nMichael 1\n')
    self.assertEqual(expected_summary, self.yn.GetSummaryText())

  def testFail(self):
    self.assertRaises(IOError, yearnames.YearNames, 'nosuchfile.html')
    # args for above: exception, callable, args
  # LAB(end solution)


if __name__ == '__main__':
  unittest.main()
