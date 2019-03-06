#!/usr/bin/python2.6

import sys

def main():
  for try_num in range(3):
    try:
      num = int(raw_input('Enter an integer: '))
      break
    except ValueError:
      if try_num == 2:
        sys.exit('Failed to give valid integer in 3 tries.')
      else:
        print 'Invalid Integer...try again.'

  print 'Your number plus two - ' + str(num + 2)

  print 'Thanks for using plus two script!'

if __name__ == '__main__':
  main()
