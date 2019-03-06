#!/usr/bin/python -tt

# A. donuts
# Given an int count of a number of donuts, return a string
# of form 'Number of donuts: <count>', where <count> is number
# passed in. 
# However, if the count is 10 or more, then use the word 'many'
# instead of the actual count. So donuts(5) returns 'Number of 
# donuts: 5' and donuts(23) returns 'Number of donuts: many'
def donuts(count):
  # +++your code here+++
  if count < 10:
    return 'Number of donuts: ' + str(count)
  else:
    return 'Number of donuts: many'        
# :) -----------------------------------------------------------------


# B. both_ends
# Given a string s, return a string made of the first 2 and the 
# last 2 chars of the original string, so 'spring' yields 'spng'.
# But if string length is less than 2, return empty string instead.
def both_ends(s):
  if len(s) < 2: 
    return ''
  else:
    sliced = s[0:2] + s[-2:]       
    #slice s so that first2 and last 2 chars remain 
    return sliced
# :) -----------------------------------------------------------------

    
# C. fix_start 
# Given a string s, return a string where all occurences of its
# first char have been changed to '*', except do not change
# the first char itself.
# e.g. 'babble' yields 'ba**le'
# Assume that the string is length 1 or more.
# Hint: s.replace(stra, strb) returns a version of string s
# where all instances of stra have been replaced by strb.
def fix_start(s):
  # +++your code here+++
  first = s[0]              
  rest  = s[1:]             
  replaced = rest.replace(first, '*')
  #in rest, replace occurence of first with '*'
  return s[0] + replaced
# :) -----------------------------------------------------------------

# D. MixUp
# Given strings a and b, return a single string with a and b separated
# by a space '<a> <b>', except swap the first 2 chars of each string.
# e.g.
#   'mix', pod' -> 'pox mid'
#   'dog', 'dinner' -> 'dig donner'
# Assume a and b are length 2 or more.
def mix_up(a, b):
  a_swap = b[0:2] + a[2:]
  b_swap = a[0:2] + b[2:]
  return a_swap +' '+ b_swap
# :) -----------------------------------------------------------------


# ====================================================================
# Provided simple test() function used in main() to print
# what each function returns vs. what it's supposed to return.
def test(got, expected):
  if got == expected:
    prefix = ' OK '
  else:
    prefix = '  X '
  print '%s got: %s expected: %s' % (prefix, repr(got), repr(expected))


# Provided main() calls the above functions with interesting inputs,
# using test() to check if each result is correct or not.
def main():
  print 'donuts'
  # Each line calls donuts, compares its result to the expected for that call.
  test(donuts(4), 'Number of donuts: 4')
  test(donuts(9), 'Number of donuts: 9')
  test(donuts(10), 'Number of donuts: many')
  test(donuts(99), 'Number of donuts: many')

  print
  print 'both_ends'
  test(both_ends('spring'), 'spng')
  test(both_ends('Hello'), 'Helo')
  test(both_ends('a'), '')
  test(both_ends('xyz'), 'xyyz')

  
  print
  print 'fix_start'
  test(fix_start('babble'), 'ba**le')
  test(fix_start('aardvark'), 'a*rdv*rk')
  test(fix_start('google'), 'goo*le')
  test(fix_start('donut'), 'donut')

  print
  print 'mix_up'
  test(mix_up('mix', 'pod'), 'pox mid')
  test(mix_up('dog', 'dinner'), 'dig donner')
  test(mix_up('gnash', 'sport'), 'spash gnort')
  test(mix_up('pezzy', 'firm'), 'fizzy perm')


# Standard boilerplate to call the main() function.
if __name__ == '__main__':
  main()
