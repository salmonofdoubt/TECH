#!/usr/bin/python2.4

import os
import re
import sys
import urllib

"""
Logpuzzle exercise
nparlante@google.com
Given an apache logfile, find the puzzle urls and download the images.
See the exercise handout at
http://wiki.corp.google.com/Codelab/PyQuickLogPuzzle

Here's what a puzzle url looks like:
172.25.132.28 - - [06/Aug/2007:00:13:48 -0700] "GET /~foo/puzzle/bar-42.jpg HTTP/1.0" 302 528 "-" "Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US; rv:1.8.1.6) Gecko/20070725 Firefox/2.0.0.6"
"""


def ReadUrls(filename):
  """Returns a list of the puzzle urls from the log file,
  extracting the hostname from the filename itself.
  Screens out duplicate urls and returns them sorted into
  increasing order."""
  # +++your code+++
  # LAB(begin solution)
  # Extract the hostname from the filename
  underbar = filename.index('_')
  host = filename[underbar + 1:]

  # Use a dict to screen out the duplicates
  url_dict = {}

  f = open(filename)
  for line in f:
    # Find the path which is after the GET and surrounded by spaces.
    match = re.search(r'"GET (\S+)', line)
    # Above uses \S (upper case S) which is any non-space char
    # Alternately could use square brackets: "GET ([^ ]+)"
    # or the ? form: "GET (.+?) "

    if match:
      path = match.group(1)
      # Add to dict if it's a special "puzzle" url
      if '/puzzle/' in path: url_dict['http://' + host + path] = 1

  return sorted(url_dict.keys(), key=UrlSortKey)
  # LAB(end solution)


# LAB(begin solution)
def UrlSortKey(url):
  """Used to order the urls in increasing order by 2nd word if present."""
  match = re.search(r'-(\w+)-(\w+)\.\w+', url)
  if match:
    return match.group(2)
  else:
    return url
# LAB(end solution)


def DownloadImages(img_urls, dest_dir):
  """Given the urls already in the correct order, downloads
  each image into the given directory.
  Gives the images local filenames img0, img1, and so on.
  Creates an index.html in the directory
  with an img tag to show each local image file.
  Creates the directory if necessary.
  """
  # +++your code+++
  # LAB(begin solution)
  if not os.path.exists(dest_dir):
    os.makedirs(dest_dir)

  index = file(os.path.join(dest_dir, 'index.html'), 'w')
  print >> index, '<html><body>'

  i = 0
  for img_url in img_urls:
    local_name = 'img%d' % i
    print 'Retrieving...', img_url
    urllib.urlretrieve(img_url, os.path.join(dest_dir, local_name))

    index.write('<img src="%s">' % (local_name,))
    i += 1

  print >> index, '\n</body></html>'
  index.close()
  # LAB(end solution)


def main():
  args = sys.argv[1:]

  if not args:
    print 'usage: [--todir dir] logfile '
    sys.exit(1)

  todir = ''
  if args[0] == '--todir':
    todir = args[1]
    del args[0:2]

  img_urls = ReadUrls(args[0])

  if todir:
    DownloadImages(img_urls, todir)
  else:
    print '\n'.join(img_urls)

if __name__ == '__main__':
  main()
