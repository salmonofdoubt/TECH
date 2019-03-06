#!/usr/bin/python2.6

import re

def main():
  library_data = open('library_data.txt', 'r').read()

  # Without the first match restriction
  start_dates = re.findall('start:(.+), end', library_data)
  print start_dates
  print ''

  # With the first match restriction
  start_dates = re.findall('start:(.+?), end', library_data)
  print start_dates
  print ''

if __name__ == '__main__':
  main()
