#!/usr/bin/python2.4 -tt


#DATA STRUCTURES - LISTS
my_list = ['sauwei', 'albert', 'hwang']
print len(my_list)    # prints 3
print '~~~\n'

print my_list[0]
print my_list[1]
print my_list[0:2]
print my_list[1:]
print '~~~\n'

print my_list[0][3]  # 1st element, 4th position "w"
print my_list[2][4]  # "g"
print my_list
print '~~~\n'


# Modify list above
my_list[0] = 'AL'
print my_list

my_list.append('aasmith') # .extend(position) .pop(position) .remove .sort
print my_list

my_list.sort()
print my_list

my_list_sorted = sorted(my_list)  # to re-assign a sorted list to a new list
print my_list_sorted              #  use the sorted() function instead:
print '~~~\n'


# FOR LOOP                        # for <loop variable> in <iterable>:
for x in my_list: 
  print 'Call me - '+ x           # x is just the place in list
print '~~~\n'

count = 0
for x in my_list:
  my_list[count] = x.upper()
  count += 1
print my_list
print '~~count~~\n'

for letter in 'ABCDEFGHIJKLMNOPQRSTUVWXYZ':
  if letter in 'AEIOU':
    print letter, 'is a vowel'
  else:   
    print letter, 'is a consonant'
print '~~~\n'


# RANGE
bottle_numbers = range(9,0,-1)  # creates a LIST 
print bottle_numbers
for x in bottle_numbers:
  print str(x) + ' bottles of beer'
print '~~~\n'

for x in range(12,0,-3):
   print str(x) + ' bottles of beer'
print '~~~\n'


my_list = ['albert', 'sauwei', 'hwang']
print my_list
for x in range(0, len(my_list), 1):   # for the lenght of the list
  my_list[x] = my_list[x].upper()
print my_list, '\n~~~\n'
if 'ALBERT' in my_list:
  print 'yes, ALBERT\'s in the list'

if 'albert' not in my_list:
  print 'but where\'s albert', '\n~~~\n'

# TUPLES
my_tuple = ('a', 'b', 'c')           # Tuple is a static 'variable', it cannot be changed, 
                                     # it is immutable

# DICTIONARIES

my_dict = {'bugs': 'rabbit',
          'elmer': 'human',
          'wiley': 'coyote',
          'tomas': 'cat',
          'jerry': 'mouse'}

print my_dict
print my_dict['elmer']
del my_dict['bugs']
print my_dict, '\n~~~\n'

print '---Keys:---'
for x in my_dict:
  print x
print '~~~\n'
  
print '---Values:---'
for x in my_dict:
  print my_dict[x]
print '~~~\n'

# FUNCTIONS
print 'FUNCTIONS'

def AddFive():                    # most primitive
  return 5
add_five = AddFive()
print add_five, '\n~~~\n'

def AddNum(num):                 
  num += 1
  return num
num_a = AddNum(5)                 # stick 5 in the function above
print num_a, '\n~~~\n'



def ConvertInches(cm):
  inches = cm/2.54
  return str(inches)              # return stops execution and return value to caller
num_inches = ConvertInches(254)
print '254 cm in inches is: ' + num_inches + '\n~~~\n'

def ConvertInchesRaw(cm=1.0):
  inches = cm/2.54
  return str(inches)
num_inches = ConvertInchesRaw()
print 'Here is the default conversion cm/inches: ' + num_inches + '\n~~~\n'
'''
num_inches_enter = raw_input('Enter value: ')
num_inches_new = ConvertInchesRaw(num_inches_enter)
print 'Result is: ' + num_inches_new + '\n~~~\n'
'''






print '~~~\t~~~\t~~~\n'















