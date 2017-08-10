#!/usr/bin/python

import sys

# Gather code in a main() function
def main():
  r = raw_input("ready to call string function? (Y)\n")
  if r == 'y' or r == 'Y':
    print string()        #calls string, takes its return value...
  else:                   #...in 'text' and prints it.
    print 'bye..'
    
def string():
  print 'Called string function'
  pi = 3.14
  text = 'Value of Pi is: ' + str(pi)
  return text           # return to calling fct
  
if __name__ == '__main__':
  main()

