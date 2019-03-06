#!/usr/bin/python2.4
# Copyright 2008 Google Inc. All Rights Reserved.

"""The ImagePuzzle class solves the google3 image puzzle for the pyquick course.

There is a wiki page which explains this exercise
http://wiki.corp.google.com/Codelab/PyQuickImagePuzzle
(sometimes given out as a printout in class).

The ImagePuzzle class encapsulates a set of image urls
which can be read from tweet pb files. The images
can be downloaded to a directory.
"""

__author__ = 'nparlante@google.com (Nick Parlante)'

# Standard modules
import os
import re
import urllib

# Google3 imports
from google3.file.base import pywrapfile
from google3.pyglib import logging

# twitter_pb is the python module name for twitter.proto
from google3.codelab.pyquick.accelerated import twitter_pb


class ImagePuzzle(object):
  """Encapsulates a collection of urls solving the PyQuick image puzzle."""

  def __init__(self):
    """Inits the ImagePuzzle to an empty state."""
    # +++your code+++
    return


  def ReadTweetUrls(self, filepattern):
    """Reads the matching files.

    Reads a tweet protocol buffers from each file and adds the url to self.

    Args:
      filepattern: files containing tweet protocol buffers
    """
    # +++your code+++
    return

  def DownloadImages(self, download_dir):
    """Downloads an image from each url into the given directory.

    Gives the images local filenames img0, img1, and so on.
    Creates an index.html in the directory with an img tag to show each
    local image file. Creates the directory if necessary.
    Args:
      download_dir: directory to write
    """
    # +++your code+++
    return



