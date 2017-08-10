#!/usr/bin/python2.4

import sys
import re
import urllib
import urlparse
import os
"""
Get Img Urls exercise
nparlante@google.com
"""

# +++Your Code+++
# Write functions and change main() to call them.


def main():
  # The arg parsing part of main() is alread done.
  # Make a list of command line arguments, omitting the [0] element
  # which is the script itself.
  args = sys.argv[1:]

  if not args:
    print 'usage: [-todir dir] url url url'
    sys.exit(1)

  todir = ''
  if args[0] == '--todir':
    todir = args[1]
    del args[0:2]

  # +++Your Code+++

if __name__ == "__main__":
  main()
