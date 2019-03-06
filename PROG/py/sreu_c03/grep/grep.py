#!/usr/bin/env python
# Copyright 2011 Google Inc. All Rights Reserved.
"""
grep.py
Created by Group 2 on 2011-12-12.
  Members:  Andre Baumann   (abaumann)
            Andrew Wachira  (wachira)
            Rodrigo Ribeiro (frib)

"""
import sys
import os
import re
import getopt

def main():
  global supress_filename
  global force_filename
  global ignore_case
# global patterns
  global trim_match
  global use_terminating_zero

  ParseOption()

  pattern = sys.argv[-2]
  filename = sys.argv[-1]

  if not supress_filename:
    prefix = filename + ':'
  else:
    prefix = ''

  f = open(filename)
  for line_number, line in PatternMatch(pattern, f):
    line = line.rstrip('\n')

    if force_filename:
      print filename + ':'

    match = prefix + repr(line_number) + ': ' + line

    if use_terminating_zero:
      print match,
    else:
      print match

  f.close()


def PatternMatch(pattern, f):
  global ignore_case

  result = []
  if ignore_case:
    flags = re.I
  else:
    flags = 0

  for line_number, line in enumerate(f.readlines()):
    match = re.search(pattern, line, flags)
    if match:
      result.append((line_number, line))

  return result

def  ParseOption():
  global supress_filename
  global force_filename
  global ignore_case
# global patterns
  global trim_match
  global use_terminating_zero
	
	
  try:
    opts, args = getopt.getopt(sys.argv[1:], "hHiF:oz")
  except getopt.GetoptError, err:
    print 'ERROR: No such option'
    sys.exit(1)

  for o, a in opts:
    if o == "-h":
      supress_filename = True
    elif o == "-H":
      force_filename = True
    elif o == "-i":
      ignore_case = True
    elif o == "-F":
      pass
    elif o == "-o":
      trim_match = True
    elif o == "-z":
      use_terminating_zero = True


if __name__ == '__main__':
  supress_filename = False
  force_filename = False
  ignore_case = False
# patterns = [None]
  trim_match = False
  use_terminating_zero = False
  main()
