#!/usr/bin/python2.6

"""
  Shows how to read a CSV into dict of dicts.

  author: alberthwang@google.com
  course: Introduction to Programming (goto/i2p)
"""

import csv

def main():
  data_file = open('data.csv', 'rU')
  dictReader_data = csv.DictReader(data_file)
  dict_data = {}

  for row_dict in dictReader_data:
    dict_data[row_dict['ldap']] = row_dict

  print 'Here are the LDAPs!'
  for ldap in dict_data:
    print ldap

  print ''

  print 'Here is the data on alberthwang'
  print dict_data['alberthwang']
  print ''

  print 'Here is alberthwang\'s department'
  print dict_data['alberthwang']['department']

if __name__ == '__main__':
  main()
