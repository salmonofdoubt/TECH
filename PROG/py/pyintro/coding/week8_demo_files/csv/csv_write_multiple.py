#!/usr/bin/python2.6

"""
  Shows how to write multiple rows to a CSV.

  author: alberthwang@google.com
  course: Introduction to Programming (goto/i2p)
"""

import csv

def main():
  data_file = open('output.csv', 'w')
  field_names = ['ldap', 'name', 'department']
  data_writer = csv.DictWriter(data_file, field_names)

  header_row = {'ldap': 'ldap',
                'name': 'name',
                'department': 'department'}

  row1 = {'ldap': 'sonyah',
          'name': 'Sonya Hetrick',
          'department': 'Engineering'}

  row2 = {'ldap': 'alberthwang',
          'name': 'Albert Hwang',
          'department': 'People Operations'}

  data = [header_row, row1, row2]

  data_writer.writerows(data)

  print 'rows written successfully.'


if __name__ == '__main__':
  main()
