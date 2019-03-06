#!/usr/bin/python

import sys

# Gather code in a main() function
def main():
  response = raw_input("Call string_find function? (Y)\n")
  if (response == 'y' or response == 'Y'):
    word = raw_input('Enter word: ')
    letter = raw_input('letter in word: ')
    print position(word, letter)  #calls position, prints return
  else:                       
    print 'bye..'
    
def position(w, l):
  print 'Received word: ', w
  print 'Received letter: ', l                     #print what was received
  returnposition = w.find(l)
  return returnposition  
  
if __name__ == '__main__':
  main()

