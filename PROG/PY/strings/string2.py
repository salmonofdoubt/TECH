#!/usr/bin/python

import sys

# Gather code in a main() function
def main():
  response = raw_input("Call string function? (Y)\n")
  if (response == 'y' or response == 'Y'):
    word = raw_input('upper case what: ')
    print string(word)        #calls string, which executes it's stuff
  else:                       #...printing the return.
    print 'bye..'
    
def string(w):
  print w                     #print what was received
  returnword = w.upper()
  return returnword  
  
if __name__ == '__main__':
  main()

