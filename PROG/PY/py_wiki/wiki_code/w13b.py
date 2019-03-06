#!/usr/bin/env python
# 13_More_Lists

import copy
a = [[1,2,3],[4,5,6]]
b = a[:]
print('a: ',a)
print('b: ',b)

c = copy.deepcopy(a)

b[0][1] = 10
c[1][1] = 12

print('a: ',a)
print('b: ',b)
print('c: ',c)
