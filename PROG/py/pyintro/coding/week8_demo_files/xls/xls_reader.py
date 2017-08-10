#!/usr/bin/python2.6

"""
  Shows how to read an XLS file by row.

  author: alberthwang@google.com
  course: Introduction to Programming (goto/i2p)
"""

import xlrd

def main():
  xls_file = xlrd.open_workbook('data.xls')

  # Get the sheetnames as a list of strings
  print 'List of sheet names:'
  print xls_file.sheet_names()
  print ''

  # Get the specific sheet you want to work with
  sheet1 = xls_file.sheet_by_name('Sheet1')

  # Print the number of rows in test sheet1
  print 'Number of rows in Sheet1:'
  print sheet1.nrows
  print ''

  # Print out the data in each row
  print 'Each Row as a List:'
  for row_num in range(sheet1.nrows):
    print sheet1.row_values(row_num)

if __name__ == '__main__':
  main()
