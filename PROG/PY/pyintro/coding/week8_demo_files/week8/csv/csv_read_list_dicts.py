#!/usr/bin/python2.6

"""
  Shows how to read a CSV into a list of dicts.

  author: alberthwang@google.com
  course: Introduction to Programming (goto/i2p)
"""

import csv

def main():
  data_file = open('data.csv', 'r')
  dictReader_data = csv.DictReader(data_file)
  list_data = []

  for row_dict in dictReader_data:
    list_data.append(row_dict)

  print 'This is the 1st row of data'
  print list_data[0]
  print ''

  print 'This is the 2nd row of data'
  print list_data[1]
  print ''

  result_str = list_data[0]['name'] + '\'s department is '
  result_str += list_data[0]['department']
  print result_str

if __name__ == '__main__':
  main()
