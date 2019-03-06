#!/usr/bin/env python
# encoding: utf-8
"""
to use Blaze, needs to run under (any) google3 directory.
url_class.py
Created by André Baumann on 2011-12-13.
Copyright (c) 2011 __MyCompanyName__. All rights reserved.
"""

import os
import sys
import urllib

dir_name = 'python-downloads'

class Downloader(object):
  def __init__(self, base_dir):
    self._base_dir = base_dir

  def _get(self, url):
    f = urllib.urlopen(url)
    data = f.read()
    f.close()
    return data

  def _save(self, data, destination):
    if os.path.exists(destination):
      return

    f = open(destination, 'w')
    f.write(data)
    f.close()

  def download(self, url):
    data = self._get(url)
    savefile_name = os.path.basename(url)  # Not great (? and what not), but I
                                           # want to keep it simple.
    destination = os.path.join(self._base_dir, savefile_name)
    self._save(data, destination)
    return os.path.getsize(destination)


if __name__ == '__main__':
  if not os.path.isdir(dir_name):
    os.mkdir(dir_name)

  downloader = Downloader(dir_name)

  while True:
    print '>>>',
    url = raw_input()
    size = downloader.download(url)
    print 'Done (%d bytes).' % size

  # Sample URLs:
  # 'http://docs.python.org/library/os.html'
  # 'http://www.prguitarman.com/comics/poptart1red1.gif'