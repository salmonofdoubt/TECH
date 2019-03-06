#!/usr/bin/python2.6

import re
import urllib

def UrlToText(url):
  url_file = urllib.urlopen(url)
  contents = url_file.read()
  return contents

def main():
  my_moma_page = 'https://orginfo.corp.google.com/alberthwang?format=xml'
  print UrlToText(my_moma_page)

if __name__ == '__main__':
  main()
