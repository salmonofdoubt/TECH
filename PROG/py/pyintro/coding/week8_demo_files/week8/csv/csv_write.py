#!/usr/bin/python2.6

"""
  Shows how to write individual rows to CSV.

  author: alberthwang@google.com
  course: Introduction to Programming (goto/i2p)
"""

import csv

def main():
  data_file = open('output.csv', 'r+')
  field_names = ['ldap', 'name', 'department']
  data_writer = csv.DictWriter(data_file, field_names)

  header_row = {'ldap': 'ldap',
                'name': 'name',
                'department': 'department'}

  data_writer.writerow(header_row)
  print 'header row written successfully.'

  row_data = {'ldap': 'smadaan',
              'name': 'Saurabh Madaan',
              'department': 'Engineering'}

  data_writer.writerow(row_data)
  print 'row written successfully.'


if __name__ == '__main__':
  main()
