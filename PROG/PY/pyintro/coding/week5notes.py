#!/usr/bin/python2.4 -tt

#W5NOTES

#DATASTRUCTURES PART II

my_list = ['sauwei', 'albert', 'hwang']

counter = 0               # is a variable, counting on 'name'
for name in my_list:
  my_list[counter] = name.upper()
  print my_list, '\n'

new_list = ['ab','bc','cd']
for tuple in enumerate(new_list):
  print tuple, '\n'

for index, name in enumerate(new_list):
  print name + ' is number ' + str(index + 1) + ' item\n'

for index, name in enumerate(new_list):
  new_list[index] = name.upper()
  print new_list, ' (within loop)'
print new_list, '(outside loop)\n'

# SPLIT 
my_string = 'albert | sauwei | hwang'
my_list = my_string.split('|')  # where to split, and make comma
print my_list[2]                # ‘hwang’
print my_list, '\n'             # [‘albert’, ‘sauwei’, ‘hwang’]

my_string = 'what the hell is going on'
my_list = my_string.split(' ')  # split at whitespace, and make comma
print my_list[2]                
print my_list, '\n'             

# DICTIONARY FUNCTIONS
dict1 = {'bugs': 'rabbit',
         'elmer': 'human',
         'wiley': 'coyote',
         'tom': 'cat',
         'jerry': 'mouse'}

for key in dict1:
  dict1_new = dict1[key].upper()
  print dict1_new, '***dict1_new***'
print '\n', dict1, '***dict1, the orignal***\n'

dict2 = {'a': '1',
         'b': '2',
         'c': '3'}

for letter,number in dict2.iteritems():
  print letter + ' is a ' + number, '\n'


# MAP

def DoubleEven(num):
  if num % 2 == 0:
    num = num * 100
  return num

list1 = [1,2,3,4,5,6,7,8,9,10]
new_list1 = map(DoubleEven, list1)
print 'The map() function: \n', new_list1, '\n'

# NESTING
my_list = [['a', 'b', 'c'], [1, 2, 3], ['d', 'e', 'f']]

print 'NESTING'
print my_list[1]            # [1, 2, 3] 
print my_list[1][1],'\n'    # 2 

my_dict = {'alberthwang': {'name': 'Albert Hwang', 
                           'eeid': 67739,
                           'title': 'internal tools developer'},
           'satishm': {'name': 'Satish Musurunu',
                       'eeid': 67238,
                       'title': 'tech lead'}}
print my_dict,'\n'
print my_dict['satishm']
print my_dict['alberthwang']
print '~~~~~~~~~EOF~~~~~~~~'










