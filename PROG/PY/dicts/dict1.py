#!/usr/bin/python

import sys

# Gather code in a main() function
def main():
  #r = raw_input("ready to call list function? (Y)\n")
  #if r == 'y' or r == 'Y':
  dicts()        #calls string, takes its return value...
  #else:               #...in 'text' and prints it.
  #print 'bye..'
    
def dicts():
    print 'Called dicts'
    dict = {}
    dict ['a'] = 'alpha'
    dict ['b'] = 'beta'
    dict ['c'] = 'beta'
    
    print 'complete structure:  ', dict
    print 'dict.items:          ', dict.items()
    print 'dict.values:         ', dict.values()
    print "key a's value:       ", dict['a']      
    #By default, iterating over dicts iterates over keys.
    #Keys are in random order on purpose (key retrieval times).
    print 'iterating over keys: '
    for key in dict: 
      print key
      
    del dict['b']
    print "deleted 'b'          ", dict
      
    hash = {}
    hash ['word'] = 'garfield'
    hash ['count'] = 42
    print '\n', hash
    s = 'I want %(count)d copies of %(word)s' % hash
    print s
        
    return                # return to calling fct
        
if __name__ == '__main__':
  main()

