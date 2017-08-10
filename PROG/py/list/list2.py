#!/usr/bin/python

import sys

# Gather code in a main() function
def main():
  
  newlist = [2,3,'ich',1,4, 'a', 1279]
  ListFunc(newlist)
  
  longlist = ['Ich','habe','grossen','Hunger', '!']
  ListLen(longlist)
  
  mytuple = [(1,'b'),(4,'f'),(2,'a')]
  Tuple(mytuple)
  
  
  coords = ('x1','y1','z1')
  nums   = (1,2,2) 
  print TupleAssign(coords, nums)

    
def ListFunc(somelist):
    print 'Called listfunc'
    
    print 'Original: ', somelist
    print 'Sorted:   ', sorted(somelist)
    print 'Reverse:  ', sorted(somelist, reverse = True)
    
    
def ListLen(longlist):
    print 'Called ListLen'
    
    print 'Original:    ', longlist
    
    print 'By lenght:   ', sorted(longlist, key = len)
    print 'By last char:', sorted(longlist, key = Last)
                           #calls fct Last to figure it
    
    print 'Join:\n'      , '\n'.join(longlist) #handy one
    print "Join by ':'  ", ':'.join(longlist)
    a = ':'.join(longlist)
    print 'Split again: ', a.split(':')                      
    
def Tuple(tuples):
    print 'O:      ', tuples
    print 'Sorted :', sorted(tuples)  

def TupleAssign(coords, nums):
    x = coords = nums
    # so effectively ('x1','y1','z1') = (1,2,2) 
    return x
    
def Last(s):
  return s[-1]
    
if __name__ == '__main__':
  main()

