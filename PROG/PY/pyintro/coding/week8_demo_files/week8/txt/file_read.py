#!/usr/bin/python2.6

"""
  Shows how to read contents of text file as string

  author: alberthwang@google.com
  course: Introduction to Programming (goto/i2p)
"""

def main():
  test_file = open('test.txt', 'r')
  content = test_file.read()
  print content

  # Get a list of the rows as strings
  rows = content.split('\n')
  print rows
  print rows[1]

if __name__ == '__main__':
  main()
