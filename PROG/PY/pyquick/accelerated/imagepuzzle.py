#!/usr/bin/python2.4
# Copyright 2008 Google Inc. All Rights Reserved.
#

"""Main() that calls imagepuzzle_lib code."""

__author__ = 'nparlante@google.com (Nick Parlante)'

import commands
import sys

# Google imports

# Google file
from google3.file.base import pywrapfile

# (The BUILD dependency for these modules is "//pyglib")
from google3.pyglib import app
from google3.pyglib import flags
from google3.pyglib import logging

from google3.codelab.pyquick.accelerated import imagepuzzle_lib


# Register our flag definitions
flags.DEFINE_string('read_tweets', '', 'tweet file path for reading')
flags.DEFINE_string('write_tweet', '', 'tweet file path for writing')
flags.DEFINE_string('download_dir', '', 'dir to create with images')
flags.DEFINE_string('zip_file', '', 'zip up the download dir to this file')

# Make FLAGS variable to hold flags, so it looks just
# like C++ code.
FLAGS = flags.FLAGS


# This checks that pywrapfile is properly set up.
# This is not something you would do for production code;
# it's just for the pyquick exercise. (provided code)
def CheckPywrapfile():
  """Checks that pywrapfile is properly loaded."""
  readable = pywrapfile.File.Readable('/etc/hostname')
  if not readable:
    logging.fatal('Pywrapfile not working. '
                  'Make sure BUILD dep //file/localfile is present.')


def main(args):
  # Checks that BUILD dep "//file/localfile" is present. If it's not there
  # file operations will fail with an unhelpful exception in file.cc.
  CheckPywrapfile()

  # Google args processing deletes all the flags stuff from args.
  # Get rid of [0] element which points to script itself.
  del args[0]

  # +++your code+++
  # Create ImagePuzzle object and call methods based on the flags above.


# This is the standard logic to detect if we are running vs. being imported.
# app.run() does basic setup and then calls back to our main() above.
if __name__ == '__main__':
  app.run()
