#!/usr/bin/python2.6

import re
import urllib

def UrlToText(url):
  url_file = urllib.urlopen(url)
  contents = url_file.read()
  return contents

def main():
  cc540_page = 'https://orginfo.corp.google.com/search/'
  cc540_page += 'cost_center_number:540?format=xml'
  cc540_str =  UrlToText(cc540_page)

  ldaps = re.findall('<email>(\w+?)</email>',
                     cc540_str)

  for ldap in ldaps:
    print ldap + ' is in Cost Center 540'

if __name__ == '__main__':
  main()
