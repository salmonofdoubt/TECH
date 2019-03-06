#!/usr/bin/python2.6

import re

def main():
  employees_file = open('employees.txt', 'r')
  employees_str = employees_file.read()
  print ''

  # Match entire pattern
  location_list = re.findall(r'Location:.+', employees_str)

  print location_list
  print ''

  # Match 1 Group
  location_list = re.findall(r'Location:(.+)', employees_str)

  print location_list
  print ''

  # Refining match to get rid of space
  location_list = re.findall(r'Location:\s(.+)', employees_str)

  print location_list
  print ''

  # Matching Multiple Groups
  location_list = re.findall(r'Location:\s(\w+)-(\w+)-(.+)',
                             employees_str)

  print location_list
  print ''

  # Another Multiple Groups Match
  name_exp = r'Name:\s(\w+)\s(\w+)'

  names_list = re.findall(name_exp, employees_str)

  print names_list
  print ''

  # No matches found
  no_match_list = re.findall(r'Cost Center:\s(\d+)',
                             employees_str)

  print no_match_list
  print ''

  # Testing if match found
  cc_match_list = re.findall(r'Cost Center:\s(\d+)',
                             employees_str)
  if len(cc_match_list) > 0:
    print cc_match_list
  else:
    print 'Cost Center Not Found.'


if __name__ == '__main__':
  main()
