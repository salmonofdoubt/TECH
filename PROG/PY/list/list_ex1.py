#!/usr/bin/python2.4 -tt

# A. MatchEnds
# Given a list of strings, return the count of the number of
# strings (words) where the string length is 2 or more and the first
# and last chars of the string are the same.
# Note: python does not have a ++ operator, but += works.
def MatchEnds(incomingList):   
  count = 0 
  for w in incomingList:
    if len(w) >= 2 and w[0] == w[-1]:  #first and last word 
      count += 1
  return count
# :) -----------------------------------------------------------------

# B. XFront
# Given a list of strings, return a list with the strings
# in sorted order, except group all the strings that begin with 'x' first.
# e.g. ['mix', 'xyz', 'apple', 'xanadu', 'aardvark'] yields
# ['xanadu', 'xyz', 'aardvark', 'apple', 'mix']
# Hint: this can be done by making 2 lists and sorting each of them.
def XFront(incomingList):
  x_list = []
  r_list = []
  for w in incomingList:
    if w[0] == 'x':
      x_list.append(w)
    else:
      r_list.append(w)
  x_list.sort()  
  r_list.sort()
  s_list = x_list + r_list
  return s_list

# :) -----------------------------------------------------------------


# C. SortLast
# Given a list of non-empty tuples, return a list sorted in increasing
# order by the last element in each tuple.
# e.g. [(1, 7), (1, 3), (3, 4, 5), (2, 2)] yields
# [(2, 2), (1, 3), (3, 4, 5), (1, 7)]
# Hint: use a custom key= function to extract the last element form each tuple.
# Help: Extract last element from a tuple -- used for custom sorting
def Last(a):
  return a[-1]                    #last e of any tuple

def SortLast(tuples):
  return sorted(tuples, key=Last) #calling Last here, more in main

# :) :) :) -----------------------------------------------------------


# ====================================================================
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
  print '---MatchEnds---'
  Test(MatchEnds(['aba', 'xyz', 'aa', 'x', 'bbb']), 3)
  Test(MatchEnds(['', 'x', 'xy', 'xyx', 'xx']), 2)
  Test(MatchEnds(['aaa', 'be', 'abc', 'hello']), 1)

  print
  print '---XFront---'
  Test(XFront(['bbb', 'ccc', 'axx', 'xzz', 'xaa']),
       ['xaa', 'xzz', 'axx', 'bbb', 'ccc'])
  Test(XFront(['ccc', 'bbb', 'aaa', 'xcc', 'xaa']),
       ['xaa', 'xcc', 'aaa', 'bbb', 'ccc'])
  Test(XFront(['mix', 'xyz', 'apple', 'xanadu', 'aardvark']),
       ['xanadu', 'xyz', 'aardvark', 'apple', 'mix'])

  print
  print '---SortLast---'
  Test(SortLast([(1, 3), (3, 2), (2, 1)]),
       [(2, 1), (3, 2), (1, 3)])
  Test(SortLast([(2, 3), (1, 2), (3, 1)]),
       [(3, 1), (1, 2), (2, 3)])
  Test(SortLast([(1, 7), (1, 3), (3, 4, 5), (2, 2)]),
       [(2, 2), (1, 3), (3, 4, 5), (1, 7)])
  
  print
  print "---SortLast cont'd---"
  list = ['aba', 'cab', 'bbc']
  def Func1(s):
    return s[0]
  def Func2(s):
    return s[1]
  def Func3(s):
    return s[2]
  
  print 'according to key on position' 
  print '0:',sorted(list, key=Func1)
  print '1:',sorted(list, key=Func2)
  print '2:',sorted(list, key=Func3)


if __name__ == '__main__':
  main()
