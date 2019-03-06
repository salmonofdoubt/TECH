#!/usr/bin/python2.4 -tt

#PART1
while True:
  no = raw_input('Enter a number 1-6: ' )
  if no == '1':
    print 'that is the best'
  elif no == '2':
    print 'that\'s the type of pencil you use in the SAT'
  elif no == '3':
    print 'that rhymes with \'me\''
  elif no == '4':
    print 'I want some more'
  elif no == '5':
    print 'like a high five'
  elif no == '6':
    print 'what a neat trick'
  else:
    print '***That is not a number 1-6***\n~~~\n'
    break

#PART2

bbw = ' bottles of beer on the wall,'
bb = ' bottles of beer...\n'
too = 'Take one out, pass it around, '
bbe = ' bottles of beer on the wall!'
yay = 'Yay! Even number!'
awe = 'Awesome, 10 down!\n' 
luck = ' IS THE LUCKY NUMBER!!!'
man = '\nOh man, I really can\'t have any more!'

k = 99
l = k - 1

while k > 0:
  print str(k) + bbw + str(k) + bb + too + str(l) + bbe
  k -= 1
  l = k - 1
  if k % 2 == 0:
    print yay
  if k % 10 == 0:
    print awe
  if k == 92:
    print str(k) + luck
  if k == 78:
    print man
    break



print '~~~\n'
