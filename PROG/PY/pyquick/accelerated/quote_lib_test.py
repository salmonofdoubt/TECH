#!/usr/bin/python2.4
# Copyright 2008 Google Inc. All Rights Reserved.

"""Simple example test class in google3.

Differences from standard python test class:
 -import googletest instead of unittest
 -subclass off googletest.TestCase instead of unittest
 -import flags and use FLAGS.test_srcdir and FLAGS.test_tmpdir
 -in the __main__ section at the bottom of the file, call googletest.main()
"""

__author__ = 'nparlante@google.com (Nick Parlante)'

import os

from google3.pyglib import flags
from google3.testing.pybase import googletest

from google3.codelab.pyquick.accelerated import quote_lib

FLAGS = flags.FLAGS


class QuoteUnitTest(googletest.TestCase):
  def testInit(self):
    quote = quote_lib.Quote('text', 'author')
    self.assertEquals('text', quote.GetText())   # getter way
    self.assertEquals('author', quote.author)    # just access it way
    # TODO(nparlante): find authorative list of what assert* methods we support

  def testFormatted(self):
    quote = quote_lib.Quote('text', 'author')
    self.assertEquals('text\n--author\n', quote.GetFormatted())

  def testFileReadWriteRoundtrip(self):
    # Make a quote object
    q1 = quote_lib.Quote('text goes here', 'author')

    # Write it to a file.
    fname = os.path.join(FLAGS.test_tmpdir, 'iofile')
    q1.WriteShirt(fname)

    # Read back and check
    q2 = quote_lib.Quote('', '')
    q2.ReadShirt(fname)
    self.assertEqual('text goes here', q2.text)
    self.assertEqual('author', q2.author)

if __name__ == '__main__':
  googletest.main()
