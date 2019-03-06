#!/usr/bin/python2.4 -tt

# Additional, optional string mini exercises.
# nparlante@google.com


# A. Verbing
# Given a string, if its length is at least 3,
# add 'ing' to its end.
# Unless it already ends in 'ing', in which case
# add 'ly' instead.
# If the string length is less than 3, leave it unchanged.
# Return the resulting string.
def Verbing(s):
  # +++your code here+++
  # LAB(begin solution)
  if len(s) >= 3:
    if s[-3:] != 'ing': s = s + 'ing'
    else: s = s + 'ly'
  return s
  # LAB(replace solution)
  # return
  # LAB(end solution)


# B. NotBad
# Given a string, find the first appearance of the
# substring 'not' and 'bad'. If the 'bad' follows
# the 'not', replace the whole 'not'...'bad' substring
# with 'good'.
# Return the resulting string.
# So 'This dinner is not that bad!' yields:
# This dinner is good!
def NotBad(s):
  # +++your code here+++
  # LAB(begin solution)
  n = s.find('not')
  b = s.find('bad')
  if n != -1 and b != -1 and b > n:
    s = s[:n] + 'good' + s[b+3:]
  return s
  # LAB(replace solution)
  # return
  # LAB(end solution)


# Simple provided Test() function used in main() to print
# what each function returns vs. what it's supposed to return.
def Test(got, expected):
  if got == expected:
    prefix = ' OK '
  else:
    prefix = 'FAIL'
  print '%s got: %s expected: %s' % (prefix, repr(got), repr(expected))


# main() calls the above functions with interesting inputs,
# using the above Test() to check if the result is correct or not.
def main():
  print 'Verbing'
  Test(Verbing('hail'), 'hailing')
  Test(Verbing('swiming'), 'swimingly')
  Test(Verbing('do'), 'do')

  print
  print 'NotBad'
  Test(NotBad('This movie is not so bad'), 'This movie is good')
  Test(NotBad('This dinner is not that bad!'), 'This dinner is good!')
  Test(NotBad('This tea is not hot'), 'This tea is not hot')
  Test(NotBad("It's bad yet not"), "It's bad yet not")


if __name__ == '__main__':
  main()
