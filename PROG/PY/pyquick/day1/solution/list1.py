#!/usr/bin/python2.4 -tt

# List mini exercises.
# nparlante@google.com


# A. MatchEnds
# Given a list of strings, return the count of the number of
# strings where the string length is 2 or more and the first
# and last chars of the string are the same.
# Note: python does not have a ++ operator, but += works.
def MatchEnds(words):
  # +++your code here+++
  # LAB(begin solution)
  count = 0
  for word in words:
    if len(word) >= 2 and word[0] == word[-1]:
      count = count + 1  # could write as: count += 1
  return count
  # LAB(replace solution)
  # return
  # LAB(end solution)


# B. XFront
# Given a list of strings, return a list with the strings
# in sorted order, except group all the strings that begin with 'x' first.
# e.g. ['mix', 'xyz', 'apple', 'xanadu', 'aardvark'] yields
# ['xanadu', 'xyz', 'aardvark', 'apple', 'mix']
# Hint: this can be done by making 2 lists and sorting each of them.
def XFront(words):
  # +++your code here+++
  # LAB(begin solution)
  # Put each word into the x_list or the other_list.
  x_list = []
  other_list = []
  for w in words:
    if w.startswith('x'):
      x_list.append(w)
    else:
      other_list.append(w)
  return sorted(x_list) + sorted(other_list)
  # LAB(replace solution)
  # return
  # LAB(end solution)


# LAB(begin solution)
# Extract the last element from a tuple -- used for custom sorting below.
def Last(a):
  return a[-1]
# LAB(end solution)

# C. SortLast
# Given a list of non-empty tuples, return a list sorted in increasing
# order by the last element in each tuple.
# e.g. [(1, 7), (1, 3), (3, 4, 5), (2, 2)] yields
# [(2, 2), (1, 3), (3, 4, 5), (1, 7)]
# Hint: use a custom key= function to extract the last element form each tuple.
def SortLast(tuples):
  # +++your code here+++
  # LAB(begin solution)
  return sorted(tuples, key=Last)
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


# Calls the above functions with interesting inputs.
def main():
  print 'MatchEnds'
  Test(MatchEnds(['aba', 'xyz', 'aa', 'x', 'bbb']), 3)
  Test(MatchEnds(['', 'x', 'xy', 'xyx', 'xx']), 2)
  Test(MatchEnds(['aaa', 'be', 'abc', 'hello']), 1)

  print
  print 'XFront'
  Test(XFront(['bbb', 'ccc', 'axx', 'xzz', 'xaa']),
       ['xaa', 'xzz', 'axx', 'bbb', 'ccc'])
  Test(XFront(['ccc', 'bbb', 'aaa', 'xcc', 'xaa']),
       ['xaa', 'xcc', 'aaa', 'bbb', 'ccc'])
  Test(XFront(['mix', 'xyz', 'apple', 'xanadu', 'aardvark']),
       ['xanadu', 'xyz', 'aardvark', 'apple', 'mix'])

  print
  print 'SortLast'
  Test(SortLast([(1, 3), (3, 2), (2, 1)]),
       [(2, 1), (3, 2), (1, 3)])
  Test(SortLast([(2, 3), (1, 2), (3, 1)]),
       [(3, 1), (1, 2), (2, 3)])
  Test(SortLast([(1, 7), (1, 3), (3, 4, 5), (2, 2)]),
       [(2, 2), (1, 3), (3, 4, 5), (1, 7)])


if __name__ == '__main__':
  main()
