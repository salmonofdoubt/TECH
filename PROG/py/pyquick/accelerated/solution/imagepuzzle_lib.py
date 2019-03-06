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
    # LAB(begin solution)
    # Store the urls as keys in a dict, using True as the value,
    # as an easy way to eliminate duplicates.
    self.urls = {}
    # LAB(replace solution)
    # return
    # LAB(end solution)

  # LAB(begin solution)
  # These basic methods are omitted from the starter file.
  def GetUrls(self):
    """Returns the urls list in sorted order."""
    return sorted(self.urls.keys())

  def AddUrl(self, url):
    """Adds a url to the collection, ignoring duplicates."""
    self.urls[url] = True

  def ClearUrls(self):
    """Deletes all the urls."""
    self.urls = {}
  # LAB(end solution)

  def ReadTweetUrls(self, filepattern):
    """Reads the matching files.

    Reads a tweet protocol buffers from each file and adds the url to self.

    Args:
      filepattern: files containing tweet protocol buffers
    """
    # +++your code+++
    # LAB(begin solution)
    (unused_code, matches) = pywrapfile.File.Match(filepattern)
    for filename in matches:
      logging.info('reading tweet pb ' + filename)
      buff = pywrapfile.File.ReadFileToStringOrDie(filename)
      # Make a tweet protocol buffer object out of the
      # binary data from the file.
      # Use the url in the tweet if present.
      tweet = twitter_pb.Tweet(buff)
      if tweet.has_url(): self.AddUrl(tweet.url())
    # LAB(replace solution)
    # return
    # LAB(end solution)

  def DownloadImages(self, download_dir):
    """Downloads an image from each url into the given directory.

    Gives the images local filenames img0, img1, and so on.
    Creates an index.html in the directory with an img tag to show each
    local image file. Creates the directory if necessary.
    Args:
      download_dir: directory to write
    """
    # +++your code+++
    # LAB(begin solution)
    if not os.path.exists(download_dir):
      os.makedirs(download_dir)
      # Like os.mkdir, but makes all the intervening dirs too

    index = file(os.path.join(download_dir, 'index.html'), 'w')
    index.write('<html><body>\n')

    i = 0
    img_urls = self.GetUrls()
    img_urls = sorted(img_urls, key=UrlSortKey)
    for img_url in img_urls:
      local_name = 'img%d' % i
      print 'Retrieving...', img_url
      urllib.urlretrieve(img_url, os.path.join(download_dir, local_name))

      index.write('<img src="%s">' % (local_name,))
      i += 1

    index.write('\n</body></html>')
    index.close()
    # LAB(replace solution)
    # return
    # LAB(end solution)

  # LAB(begin solution)
  # Utility, not part of student code.
  def WriteTweet(self, filename, text, url):
    """Writes the file with a Tweet pb with the given info.

    Used to create the starter data files.
    Args:
      filename: file to write
      text: text
      url: url
    """
    tweet = twitter_pb.Tweet()
    tweet.set_comment(text)
    if url: tweet.set_url(url)
    pywrapfile.File.WriteStringToFileOrDie(tweet.Encode(), filename)
  # LAB(end solution)


# LAB(begin solution)
def UrlSortKey(url):
  """For custom sorting, returns the  @...@ words
     if present, otherwise returns the url unchanged."""
  match = re.search(r'@(\w+)@', url)
  if match:
    return match.group(1)
  else:
    return url
# LAB(end solution)
