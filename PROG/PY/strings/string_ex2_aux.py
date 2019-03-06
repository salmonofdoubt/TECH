#!/usr/bin/env python
# encoding: utf-8
"""
STD BOILERPLATE
Created by André Baumann on 2011-08-23.
Copyright (c) Google Inc. 2011. All rights reserved.
"""
import sys
import os


def main():
  word1 = 'Andr'
  word2 = 'Bau'
  front_back(word1, word2)

def front_back(a, b):
  
  if len(a) %2 == 0:
    a_even_1 = a_even_2  = len(a) / 2
    #print str(a_even_1) +' '+ str(a_even_2)
    #print a[:a_even_1]
    #print a[a_even_2:]
  else:
    a_odd_1 = (len(a) + 1) / 2
    a_odd_2 = (len(a) - 1) / 2
    #print str(a_odd_1) +' '+ str(a_odd_2)
    #print a[:a_odd_1]
    #print a[a_odd_2+1:]
  
  if len(b) %2 == 0:
    b_even_1 = b_even_2  = len(b) / 2
    #print str(b_even_1) +' '+ str(b_even_2)
    #print b[:b_even_1]
    #print b[b_even_2:]
  else:
    b_odd_1 = (len(b) + 1) / 2
    b_odd_2 = (len(b) - 1) / 2
    #print str(b_odd_1) +' '+ str(b_odd_2)
    #print b[:b_odd_1]
    #print b[b_odd_2+1:]
    
  if len(a) %2 == 0 and len(b) %2 == 0:
    print a[:a_even_1] + b[:b_even_1] + a[a_even_2:] + b[b_even_2:]
  
  elif len(a) %2 == 1 and len(b) %2 == 0:
    print a[:a_odd_1] + b[:b_even_1] + a[a_odd_2+1:] + b[b_even_2:]

  elif len(a) %2 == 0 and len(b) %2 == 1:
    print a[:a_even_1] + b[:b_odd_1] + a[a_even_2:] + b[b_odd_2+1:]
  
  elif len(a) %2 == 1 and len(b) %2 == 1: 
    print a[:a_odd_1] + b[:b_odd_1] + a[a_odd_2+1:] + b[b_odd_2+1:]
    
     
  return

if __name__ == '__main__':
  main()