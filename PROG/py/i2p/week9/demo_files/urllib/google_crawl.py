#!/usr/bin/python2.6

import re
import urllib

def UrlToText(url):
  url_file = urllib.urlopen(url)
  contents = url_file.read()
  return contents

def main():
  print UrlToText('http://www.google.com')

if __name__ == '__main__':
  main()
