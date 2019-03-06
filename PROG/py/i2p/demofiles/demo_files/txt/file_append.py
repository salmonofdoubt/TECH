#!/usr/bin/python2.6

"""
  Shows how to read contents of text file as string

  author: alberthwang@google.com
  course: Introduction to Programming (goto/i2p)
"""

def main():
  test_file = open('output.txt', 'a')

  added_content = '\nnew line of stuff!'

  test_file.write(added_content)

  print 'appended.'

if __name__ == '__main__':
  main()
