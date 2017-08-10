#!/usr/bin/python2.6

import re

def main():
  employees_file = open('employees.txt', 'r')
  employees_str = employees_file.read()
  print ''

  # Search for one match
  title_match = re.search(r'Report Title:\s(.+)', employees_str)
  print title_match.group(0)
  print title_match.group(1)
  print ''

  # Search for one match but with multiple groups
  updated_match = re.search(r'Last Updated:\s(\d+)/(\d+)/(\d+)',
                            employees_str)
  print updated_match.group(0)
  print updated_match.group(1)
  print updated_match.group(2)
  print updated_match.group(3)
  print ''

  # Search for one match but multiple found
  location_match = re.search(r'Location:\s(.+)', employees_str)
  print location_match.group(1)
  print ''

  # Testing if a match is found
  cc_match = re.search(r'Cost Center:(\d+)', employees_str)
  if cc_match is not None:
    print cc_match.group(1)
  else:
    print 'No Cost Center Found.'


if __name__ == '__main__':
  main()
