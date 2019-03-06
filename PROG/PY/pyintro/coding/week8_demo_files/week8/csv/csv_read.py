#!/usr/bin/python2.6

"""
  Shows how to read a CSV and print each row (as dict).

  author: alberthwang@google.com
  course: Introduction to Programming (goto/i2p)
"""

import csv

def main():
  data_file = open('data.csv', 'rU')
  dictReader_data = csv.DictReader(data_file)

  for row in dictReader_data:
    print row

if __name__ == '__main__':
  main()
