#!/usr/bin/python2.6

import re
import urllib

def UrlToText(url):
  url_file = urllib.urlopen(url)
  contents = url_file.read()
  return contents

def main():
  my_moma_page = 'https://orginfo.corp.google.com/alberthwang?format=xml'
  employee_str =  UrlToText(my_moma_page)

  cc_match = re.search('<cost_center_number>(\d+)</cost_center_number>',
                       employee_str)

  print cc_match.group(1)

if __name__ == '__main__':
  main()
