#!/usr/bin/python2.4
# Copyright 2008 Google Inc. All Rights Reserved.
#

"""Tests for the image puzzle lib."""

__author__ = 'nparlante@google.com (Nick Parlante)'

# This file should no longer be included with the starter files

import os

from google3.pyglib import flags
from google3.testing.pybase import googletest

from google3.codelab.pyquick.accelerated.solution import imagepuzzle_lib

FLAGS = flags.FLAGS


class ImagePuzzleUnitTest(googletest.TestCase):
  def testAddUrls(self):
    ip = imagepuzzle_lib.ImagePuzzle()
    ip.AddUrl('http://foo?aa=bb')
    ip.AddUrl('file:a.html')
    ip.AddUrl('file:b.html')
    ip.AddUrl('file:a.html')
    ip.AddUrl('http://foo?aa=bb')

    self.assertEqual(['file:a.html', 'file:b.html', 'http://foo?aa=bb'],
                     ip.GetUrls())

    ip.ClearUrls()
    self.assertEqual([], ip.GetUrls())

  def testFileReadWriteRoundtrip(self):
    ip = imagepuzzle_lib.ImagePuzzle()

    fname = os.path.join(FLAGS.test_tmpdir, 'fileio1')
    ip.WriteTweet(fname, 'text', 'file:a.html')

    fname = os.path.join(FLAGS.test_tmpdir, 'fileio2')
    ip.WriteTweet(fname, 'text', 'file:b.html')

    ip.ReadTweetUrls(os.path.join(FLAGS.test_tmpdir, 'fileio?'))
    self.assertEqual(['file:a.html', 'file:b.html'],
                     ip.GetUrls())

if __name__ == '__main__':
  googletest.main()
