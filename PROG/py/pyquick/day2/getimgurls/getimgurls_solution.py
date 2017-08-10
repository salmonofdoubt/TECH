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

def GetImgUrls(url):
  """Given a url, downloads its text and returns a list of all the img urls
  found inside. The returned urls are converted to absolute form.
  Returns the empty list if the url is bad."""
  try:
    # Makes file-like object out of url -- supports read() etc.
    # (these might throw an exception)
    file = urllib.urlopen(url)
    info = file.info()
    #print info
    if info.gettype() != 'text/html': return []

    baseurl = file.geturl()  # official base url of this request
    text = file.read()  # get the text

    # Pull out the src url from the <img tag
    tuples = re.findall(r'<img.*?src\s*=\s*"?(.*?)("|\s|>)',
                        text, re.IGNORECASE + re.DOTALL)
    urls = []
    for tuple in tuples: urls.append(tuple[0])
    # Above is a good candidate for a comprehension
    dict = {}
    result = []

    # Store all the urls into a dict, just to eliminate duplicates
    for url in urls: dict[url] = 1
    for url in dict.keys():
      result.append(urlparse.urljoin(baseurl, url))
    return result
  except IOError:
    # Control jumps down here on runtime exception
    print 'Warning, problem with url:', url
    return []

def WriteImgDir(dir, urls):
  """Given a dir path and a list of image urls, downloads the images
  into the directory, named img0, img1, ..., and writes an index.html
  in the directory with an <img> tag for each image. Creates the directory
  if needed."""
  if not os.path.exists(dir):
    os.mkdir(dir)

  i = 0
  out = file(os.path.join(dir, 'index.html'), 'w')
  print >> out, '<html><body>'

  for url in urls:
    name = 'img' + str(i)
    print 'Retrieving...' + url
    urllib.urlretrieve(url, os.path.join(dir, name))
    print >> out, '<p>' + url + '<br><img src=' + name + '>'
    i = i + 1

  print >> out, '</body></html>'
  out.close()


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
  urls = []
  for arg in args:
    img_urls = GetImgUrls(arg)
    urls.extend(img_urls)

  if todir: WriteImgDir(todir, urls)
  else: print '\n'.join(urls)

if __name__ == "__main__":
  main()
