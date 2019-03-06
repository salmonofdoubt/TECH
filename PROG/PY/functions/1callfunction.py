#!/usr/bin/python

import sys

# Gather code in a main() function
def main():
  print 'Hello there'
  a = raw_input("Whats up: ")
  print repeat(a, False)
  print repeat(a, True)
   
def repeat(s, exclaim):
  result = s + s + s
  if exclaim:
    result = result + '!!!'
  return result


if __name__ == '__main__':
  main()

