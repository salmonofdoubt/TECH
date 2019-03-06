#!/usr/bin/python2.4 -tt

# A. Given a list of numbers, return a list where
# all adjacent == elements have been reduced to a single element,
# so [1, 2, 2, 3] returns [1, 2, 3]. You may create a new list or
# modify the passed in list.
def RemoveAdjacent(nums):
  print 'Reveived: ', nums
  res = []                #start w/ empty list
  for n in nums:          #iterate over nums
    if len(res) == 0 or n != res[-1]: 
                          #..or xth elem in nums is not equal
                          #...last elem in res. 
      res.append(n) 
  return res  
# :) -----------------------------------------------------------------

# B. Given two lists sorted in increasing order, create and return a 
# merged list of all the elements in sorted order. 
# You may modify the passed in lists.
# Ideally, the solution should work in "linear" time, making a single
# pass of both lists.
def LinearMerge(list1, list2):
  merge = sorted(list1 + list2)
  return merge
  
# :) -----------------------------------------------------------------

#=====================================================================
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
  print 'RemoveAdjacent'
  Test(RemoveAdjacent([1, 2, 2, 3]), [1, 2, 3])
  Test(RemoveAdjacent([2, 2, 3, 3, 3]), [2, 3])
  Test(RemoveAdjacent([1]), [1])
  Test(RemoveAdjacent([]), [])

  print
  print 'LinearMerge'
  Test(LinearMerge(['aa', 'xx', 'zz'], ['bb', 'cc']),
       ['aa', 'bb', 'cc', 'xx', 'zz'])
  Test(LinearMerge(['aa', 'xx'], ['bb', 'cc', 'zz']),
       ['aa', 'bb', 'cc', 'xx', 'zz'])
  Test(LinearMerge(['aa', 'aa'], ['aa', 'bb', 'bb']),
       ['aa', 'aa', 'aa', 'bb', 'bb'])


if __name__ == '__main__':
  main()
