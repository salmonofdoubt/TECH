#!/usr/bin/env python
import readline

n = int(input('Number? '))
if n < 0:
   print "The absolute value of", n, "is", -n
else:
   print "The absolute value of", n, "is", n

input("\n\n next run")