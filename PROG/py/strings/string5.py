#!/usr/bin/python

import sys

# Gather code in a main() function
def main():
  response = raw_input("Call string_find function? (Y)\n")
  if (response == 'y' or response == 'Y'):
    name = raw_input('Enter name: ')
    number = raw_input('Enter number: ')
    substitute(name, number)      #calls fct...
  else:                       
    print 'bye..'
    
def substitute(na, nu):
  print 'Received name: ', na
  print 'Received number: ', nu  #...print what was received
  print 'Hi %s there are %s donuts.' % (na,nu)

  
if __name__ == '__main__':
  main()

