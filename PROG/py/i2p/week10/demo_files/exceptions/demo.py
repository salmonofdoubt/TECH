#!/usr/bin/python2.6

import sys

def main():
  for i in range(3):
    try:
      num = raw_input('enter an int: ')
      print 10/int(num)
      break
    except ValueError:
      if i == 2:
        sys.exit('3 tries is enough!')
      else:
        print 'Invalid Int...try again.'

  print 'thanks for using this stupid tool'

if __name__ == '__main__':
  main()
