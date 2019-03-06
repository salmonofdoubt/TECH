#!/usr/bin/python2.4 -tt

old = 'sUpERcaLaFragaliSticeXPialaDoshuS'
lwr = old.lower()
upp = old.upper()
print lwr 
print upp
print '~~~\n'

repl1 = old.replace('U','ooo')
repl2 = repl1.replace('E','aaa')
print repl2
print '~~~\n'


input1 = raw_input('Enter an Integer: ')
remainder = int(input1) % 3
print input1
print remainder

print 'Thanks, if you divide ' + input1 + ' by 3, '  'you get a remainder of'
print remainder

print '~~~\n'
