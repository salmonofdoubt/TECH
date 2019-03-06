#!/usr/bin/python2.6

"""
  Shows how to read a column from an XLS file.

  author: alberthwang@google.com
  course: Introduction to Programming (goto/i2p)
"""

import xlrd

def main():
  xls_file = xlrd.open_workbook('data.xls')
  col3_data = []

  # Get the specific sheet you want to work with
  sheet1 = xls_file.sheet_by_name('Sheet1')

  # Print out the data in each row
  for row_num in range(sheet1.nrows):
    col3_data.append(sheet1.cell(row_num, 2).value)

  print col3_data

if __name__ == '__main__':
  main()
