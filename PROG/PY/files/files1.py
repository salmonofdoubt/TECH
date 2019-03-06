#!/usr/bin/python

import sys, codecs

# Gather code in a main() function
def main():
  #r = raw_input("ready to call list function? (Y)\n")
  #if r == 'y' or r == 'Y':
  files()        #calls string, takes its return value...
  #else:               #...in 'text' and prints it.
  #print 'bye..'
    
def files():
  print 'Called files'
  
  f = open('tmp.py', 'r+')
  for line in f:
    print line
    
  a = raw_input('Add something: ')
  f.write(a)
    
  
  f = open('tmp.py', 'r')
  for line in f:
    print line

  f.close()  
            
  return                # return to calling fct
        
if __name__ == '__main__':
  main()

