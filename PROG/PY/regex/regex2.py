#!/usr/bin/python

import sys, re

def main():
  
  pattern = '...ig'
  text = 'piiig xyzg'
  
  match = regex(pattern, text)    #1.sending this to regex which takes it as (p,m)
  
  if match == 'not found':        #5.to see the actual match
  else:
    print 'found: ', match.group()  
      
def regex(p, m):                  #2.receives 'pattern' and 'text', uses them as (p,m)
    print 'Called regex'
    
    nf = 'not found'
    match = re.search(p,m)        #3.re fct w/ (pattern, text)
    if match: 
      return match                #4.return this to calling fct
    else:
      match = nf
      return match
          
if __name__ == '__main__':
  main()

