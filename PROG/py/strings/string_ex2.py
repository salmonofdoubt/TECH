#!/usr/bin/python2.4 -tt
import string

# D. verbing
# Given a string, if its length is at least 3, add 'ing' to its end.
# Unless it already ends in 'ing', in which case add 'ly' instead.
# If the string length is less than 3, leave it unchanged.
# Return the resulting string.
def verbing(s):
  if len(s) >= 3:
    if s[-3:] != 'ing':     #last 3 chars
      s = s + 'ing'         #then add ing
    else:
      s = s + 'ly'          #add ly
    return s                #s >= 3
  return s                  #s < 3

# :) -----------------------------------------------------------------


# E. not_bad
# Given a string, find the first appearance of the substring 'not'
# and 'bad'. If the 'bad' follows the 'not', replace the whole 
# 'not'...'bad' substring with 'good'.
# Return the resulting string.
# So 'This dinner is not that bad!' yields: This dinner is good!
def not_bad(s):
  n = s.find('not')
  b = s.find('bad')
  if n is not False and b is not False and n < b:
    s = s[:n] + 'good' + s[b+3:]
    #everything to not +...+ everything to 'bad', skipping the 3 chars
  return s
#for some reason
#if n != -1 and b != -1 and n < b:     -- works too
#but these don't work
#if n is True and b is True and n < b: ...
#if n == 1 and b == 1 and n < b: ... 

# :) -----------------------------------------------------------------


# F. front_back
# Consider dividing a string into two halves.
# If the length is even, the front and back halves are the same length.
# If the length is odd, we'll say that the extra char goes in the front half.
# e.g. 'abcde', the front half is 'abc', the back half 'de'.
# Given 2 strings, a and b, return a string of the form
#  a-front + b-front + a-back + b-back
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
    return a[:a_even_1] + b[:b_even_1] + a[a_even_2:] + b[b_even_2:]
  
  elif len(a) %2 == 1 and len(b) %2 == 0:
    return a[:a_odd_1] + b[:b_even_1] + a[a_odd_2+1:] + b[b_even_2:]

  elif len(a) %2 == 0 and len(b) %2 == 1:
    return a[:a_even_1] + b[:b_odd_1] + a[a_even_2:] + b[b_odd_2+1:]
  
  elif len(a) %2 == 1 and len(b) %2 == 1: 
    return a[:a_odd_1] + b[:b_odd_1] + a[a_odd_2+1:] + b[b_odd_2+1:]

'''suggested solution
  
  a_middle = len(a) / 2         
  b_middle = len(b) / 2         
  if len(a) % 2 == 1:           # it's a cheat 13/2 = 6.5
    a_middle = a_middle + 1     # but here 6.5 = 6, so 6 + 1 is OK
  if len(b) % 2 == 1:
    b_middle = b_middle + 1 
  return a[:a_middle] + b[:b_middle] + a[a_middle:] + b[b_middle:] 
    
'''

# :) -----------------------------------------------------------------



# ====================================================================
# Simple provided test() function used in main() to print
# what each function returns vs. what it's supposed to return.
def test(got, expected):
  if got == expected:
    prefix = ' OK '
  else:
    prefix = '  X '
  print '%s got: %s expected: %s' % (prefix, repr(got), repr(expected))


# main() calls the above functions with interesting inputs,
# using the above test() to check if the result is correct or not.
def main():
  print 'verbing'
  test(verbing('hail'), 'hailing')
  test(verbing('swiming'), 'swimingly')
  test(verbing('do'), 'do')

  print
  print 'not_bad'
  test(not_bad('This movie is not so bad'), 'This movie is good')
  test(not_bad('This dinner is not that bad!'), 'This dinner is good!')
  test(not_bad('This tea is not hot'), 'This tea is not hot')
  test(not_bad("It's bad yet not"), "It's bad yet not")

  print
  print 'front_back'
  test(front_back('abcd', 'xy'), 'abxcdy')
  test(front_back('abcde', 'xyz'), 'abcxydez')
  test(front_back('Kitten', 'Donut'), 'KitDontenut')

if __name__ == '__main__':
  main()
