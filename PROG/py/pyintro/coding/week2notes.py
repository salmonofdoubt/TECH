#!/usr/bin/python2.4 -tt

#STRINGS

x = 2 
y = 3
z = x + y
print 'z \n~~~\n'

my_str = 'hi'
print my_str 
print '~~~\n'

print 'I really wonder about this so called \'cheese\' in...\n~~~\n'


old_str = 'superfluous'
new_str = old_str[0]
print new_str                     #'s'
print(old_str[3]), '\n~~~\n'      #'e'

new_str = old_str[0:2]
print new_str                      #'su'
print(old_str[2:6])                # perf
print '~~~\n'

#REPLACE
old_str = 'superfluous'
new_str = old_str.replace('super', 'SUPA')
print new_str[0:6]
print '~~~\n'

#Lower() Upper()
old_str = 'SuperFluous'
print old_str.lower()
print old_str.upper()
print '~~~\n'

#Strip
old_str = ' Su per  fluous '
new_str = old_str.strip()               #strips trailing or leading spaces
print old_str
print new_str
print '~~~\n'

#I/O
name = raw_input('Name: ')
print 'Hi ' + name
print '~~~\n'


int1 = 3
int2 = 4
int3 = int1 + int2
print int3
int4 = int1 % int2
print int4
print '~~~\n'

#Casting

str1 = 'I have'
int1 = 99
str2 = 'bootles of beer on the wall'
print str1 + ' ' + str(int1) + ' ' + str2       #needs str(), otherwise incompatible operation

str1 = '1'
int1 = 99
print int(str1) + int1
print '~~~\n'




















'''.'''
