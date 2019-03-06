#!/usr/bin/python2.6

"""
  Shows how to write a list of lists to XLS.

  author: alberthwang@google.com
  course: Introduction to Programming (goto/i2p)
"""

import xlwt

def main():
  # Create a target XLS workbook object(WB) to write to
  target_wb = xlwt.Workbook()

  # Create a sheet in the WB to work with
  target_sheet = target_wb.add_sheet('Sheet 1')

  # Data to be written
  data = [[1, 5, 7, 8, 9, 20],
          ['saurabh', 'sauwei', 'hwang', 'jr.'],
          [3.6, 7.7, 8.8, 2032.6]]

  # Write the data into the sheet
  for row_num, row_data in enumerate(data):
    for col_num, col_value in enumerate(row_data):
      target_sheet.write(row_num, col_num, col_value)

  # Save the WB object to the destination file
  target_wb.save('output.xls')

  print 'done.'

if __name__ == '__main__':
  main()
