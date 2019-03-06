#!/usr/bin/env python

print '\n---if---\n'

n = int(input("number? "))
if n < 0:
    print 'abs value of' , n, 'is' , -n
else:
    print 'abs value of' , n, 'is' , n

raw_input() #not sure how else to pause the program
print '\n---elif---\n'
raw_input()

a = 0
while a < 12:
    a = a + 1
    if a > 7:
        print a,'>', 7
    elif a == 7:
        print a, '=', 7
    elif a <= 7:
       print a, '<', 7
    else:
        print 'neither test was true'

print '\n---end---\n'        








        