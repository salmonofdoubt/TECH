
PYTHON STD CLASS
help(command)
TBD:
+ strings2
+ list2
- split, join
- listtest.py
- dictionaries


---Dictionary---

keys:values

y = {}
y['a'] = 'alpha'
y['b'] = 'beta'
y['g'] = 'gamma'
print y
{'a': 'alpha', 'b': 'beta', 'g': 'gamma'}

print y['a']
alpha
y['a'] = 6
print y
{'a': 6, 'b': 'beta', 'g': 'gamma'}

for x in y: print x						#use x or anything, always prints the key
... 
a
b
g

for x in y.values(): print x	
... 
6
beta
gamma



y = {}
y[0] = 1
y[1000] = 1
y[10000] = 1
y
{0: 1, 1000: 1, 10000: 1}


---Tulples---
tuples are inmutable lists
tup = (1,2,'hi')
print len(tup)
3
print tup[2]
hi

tup[2] = 'bye'
...'tuple' object does not support item assignment

*but*
tup = ('hi')
tup
'hi'

(x,y,z)=(23,45,'hint')
x
23
y
45
z
'hint'


---List---

line = '32 4$ tomato'
line.split(',')
['32', ' 4$', ' tomato']
a = line.split(",")
separator = ":" 
separator.join(a)
'32: 4$: tomato'
---------------------------------
sorted() makes *new* list,
.sort() *modifies* existing list:
---------------------------------
a = [5,2,1,7]
print sorted(a)
[1, 2, 5, 7]
print a
[5, 2, 1, 7]

a.sort()
print a
[1, 2, 5, 7]

strss = ['klfr','drewscd','ssef','qefhbfgh']
print sorted(strss[1])
['c', 'd', 'd', 'e', 'r', 's', 'w']

sorted(a, key=len)
['d', 'bb', 'aaa', 'cccccc']

a = ['aaa', 'bb', 'cccccc', 'd']
sorted(a)
['aaa', 'bb', 'cccccc', 'd']

--- %Operator ---
'I ate %d donuts at %d am' % (4,10)
'I ate 4 donuts at 10 am'


if a != '': print 'non-empty'
... 
non-empty

if a:
...  print 'True'
... 
True

---Find---
a
'asdf'
a.find('x')
-1



---Slice---
a
'Andre'
print s[:-3]
An
print s[-3:]
dre 


---Import---
import sys
sys.something 

---Data types--- 
str(200)

help(str)

---Inpreter---
#!/usr/bin/python2.4 -tt
>>


---Main---
executes the main function if there is no module instead:
<<
# This is the standard boilerplate that calls the main() function.
if __name__ == '__main__':
  main()
>>