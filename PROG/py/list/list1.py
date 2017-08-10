#!/usr/bin/python

import sys

# Gather code in a main() function
def main():
  #r = raw_input("ready to call list function? (Y)\n")
  #if r == 'y' or r == 'Y':
  listfunc()        #calls string, takes its return value...
  #else:               #...in 'text' and prints it.
  #print 'bye..'
    
def listfunc():
    print 'Called listfunc'
    
    colors = ['red', 'blue', 'green']
    print len(colors), colors
    if 'blue' in colors:
      print "found 'blue'"
    
    i = 0
    while i < len(colors):
      print colors[i]
      i = i + 2
      
    colors.append('white')        # append elem at end
    colors.insert(1, 'gray')      # insert elem at index 0
    colors.extend(['silver', 'brown'])  # add list of elems at end
    print colors
    
    print colors.index('silver')  #5

    colors.remove('blue')         #search and remove that element
    if 'blue' not in colors:
      print "'blue' not found"
    
    colors.pop(1)         # simply removes anything on position 1 
    print colors
        
    return                # return to calling fct
        
if __name__ == '__main__':
  main()

