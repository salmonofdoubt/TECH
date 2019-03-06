#!/usr/bin/python2.4 -tt


#CODE BLOCK
'''
if my_finger.iscut == True:
  wash(my_finger)
  band(my_finger)
'''
#ELSE
int1 = raw_input('Number 1: ' )
int2 = raw_input('Number 2: ' )
if int1 == int2 or int1 > int2:
  print 'int1 is equal or greater to int2'
else:                                          #else always executes to the nearest 'if'
  print 'int1 is not equal or greater to int2'
print '~~~\n'

#ELIF
day = raw_input('Initials of day of week: ' )
day_lwr = day.lower()
if day_lwr == 'mon':
  print 'Monday'
elif day_lwr == 'tue':
  print 'Tuesday'
elif day_lwr == 'wed':
  print 'Wednesday'
elif day_lwr == 'thu':
  print 'Thursday'
elif day_lwr == 'fri':
  print 'Friday'
elif day_lwr == 'sat':
  print 'Saturday'
elif day_lwr == 'sun':
  print 'Sunday'
elif day_lwr != 'mon'or'tue'or'wed'or'thu'or'fri'or'sat'or'sun':
  print 'unrecognized'
print '~~~\n'

#INCREMENTOR/DECREMENTOR
str1 = 'hi'
print str1
str1 += ' there(!)'
print str1
'''
str1 -= '(!)'
print str1                      #won't work
'''

#WHILE
int1 = 0
while int1 < 6:                 #Careful not to create infinite loops
  print int1
  int1 += 1                     #counter
print '~~~\n'

int1 = 0
while int1 < 6:
  print int1
  if int1 == 3:
    print 'break at 3'
    break
  int1 += 1                     #counter
print '~~~\n'
