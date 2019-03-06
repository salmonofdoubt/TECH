#!/usr/bin/python

import sys
import re


def PrintMatch(pattern, f):
  text = f.read()
  m = re.match(pattern, text)
  if m is None:
    print 'no match'
  else:
    print m.group()


def main():
  args = sys.argv[1:]

  if not args:
    print 'usage: [--filelocation dir] file '
    sys.exit(1)

  for filename in args:
    pattern = raw_input('regex pattern: ' )
    f = open(filename, 'rU')
    PrintMatch(pattern, f)
    f.close()

if __name__ == "__main__":
  main()





