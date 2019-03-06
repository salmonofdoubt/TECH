#!/usr/bin/python2.6

"""
  Shows how to read contents of text file as string

  author: alberthwang@google.com
  course: Introduction to Programming (goto/i2p)
"""

def main():
  test_file = open('output.txt', 'w')

  new_content = 'This will over write werewrwe test.txt!'

  test_file.write(new_content)

  print 'written.'

if __name__ == '__main__':
  main()
