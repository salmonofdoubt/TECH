#!/usr/bin/python2.4 -tt

# String mini-exercises.
# nparlante@google.com
#
# Fill in the code for the functions below. main() is already set up
# to call the functions with a few different inputs,
# printing 'OK' when each is correct.
# The starter code for each function includes a 'return'
# which is just a placeholder for your code.
# It's ok if you do not complete all the functions, and there
# are some additional functions to try in string2.py.


# A. Donuts
# Given an int count of a number of donuts, return a string
# of the form 'Number of donuts: <count>', where <count> is the number
# passed in. However, if the count is 10 or more, then use the word 'many'
# instead of the actual count.
# So Donuts(5) returns 'Number of donuts: 5'
# and Donuts(23) returns 'Number of donuts: many'
def Donuts(count):
  if count < 10:
    return 'Number of donuts: ' + str(count)
  else:
    return 'Number of donuts: ' +'many'

# B. BothEnds
# Given a string s, return a string made of the first 2
# and the last 2 chars of the original string,
# so 'spring' yields 'spng'. However, if the string length
# is less than 2, return instead the empty string.
def BothEnds(s):
  if len(s) < 2:
    return ''
  first_two = s[0:2]
  last_two = s[-2:]
  return first_two + last_two

# C. FixStart
# Given a string, return a string where all occurrences
# of its first char have been changed to '*', except
# do not change the first char itself.
# e.g. 'babble' -> 'ba**le'
# Assume that the string is length 1 or more.
# Hint: s.replace(stra, strb) returns a version of string s
# where all instances of stra have been replaced by strb.
def FixStart(s):
  first = s[0]
  tobereplaced = s[1:]
  fixed = tobereplaced.replace(first, '*')
  return first + fixed

# D. MixUp
# Given strings a and b, return a single string with a and b separated
# by a space '<a> <b>', except swap the first 2 chars of a with the first
# 2 chars of b.
# e.g.
#   'mix', pod' -> 'pox mid'
#   'dog', 'dinner' -> 'dig donner'
# Assume a and b are length 2 or more.
def MixUp(a, b):
  a_swapped = b[:2] + a[2:]
  b_swapped = a[:2] + b[2:]
  return a_swapped + ' ' + b_swapped

#+++++++++++++++++++++++++++++++++++++++++++++++++++++++++
# Provided simple Test() function used in main() to print
# what each function returns vs. what it's supposed to return.
def Test(got, expected):
  if got == expected:
    prefix = ' OK '
  else:
    prefix = 'FAIL'
  print '%s got: %s expected: %s' % (prefix, repr(got), repr(expected))


# Provided main() calls the above functions with interesting inputs,
# using Test() to check if each result is correct or not.
def main():
  # Each line calls Donuts() and compares its result
  # to the expected for that call.
  print 'Donuts'
  Test(Donuts(4), 'Number of donuts: 4')
  Test(Donuts(9), 'Number of donuts: 9')
  Test(Donuts(10), 'Number of donuts: many')
  Test(Donuts(99), 'Number of donuts: many')

  print
  print 'BothEnds'
  Test(BothEnds('spring'), 'spng')
  Test(BothEnds('Hello'), 'Helo')
  Test(BothEnds('a'), '')
  Test(BothEnds(''), '')  # should work even with the empty string
  Test(BothEnds('xyz'), 'xyyz')

  print
  print 'FixStart'
  Test(FixStart('babble'), 'ba**le')
  Test(FixStart('aardvark'), 'a*rdv*rk')
  Test(FixStart('google'), 'goo*le')
  Test(FixStart('donut'), 'donut')

  print
  print 'MixUp'
  Test(MixUp('mix', 'pod'), 'pox mid')
  Test(MixUp('dog', 'dinner'), 'dig donner')
  Test(MixUp('gnash', 'sport'), 'spash gnort')
  Test(MixUp('pezzy', 'firm'), 'fizzy perm')

# Standard boilerplate to call the main() function.
if __name__ == '__main__':
  main()
