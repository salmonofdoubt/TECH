#!/usr/bin/env python
# encoding: utf-8
"""
tmp1.py

Created by André Baumann on 2011-12-13.
Copyright (c) 2011 __MyCompanyName__. All rights reserved.
"""

import re
import urllib

def UrlToText(url):
  url_file = urllib.urlopen(url)
  contents = url_file.read()
  return contents
  
def main():
  my_moma_page = 'http://www.google.de'
  url_contents = UrlToText(my_moma_page)
  print url_contents

if __name__ == '__main__':
  main()
