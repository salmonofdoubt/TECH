#!/usr/bin/python2.4 -tt

#W5HOMEWORK REG

# 1. bumping up a list by 2, using for loop

my_list = range(1,11)
print 'o-list: \n', my_list, '\n\n'

for index,num in enumerate(my_list):
  my_list[index] = num + 2
print 'new list: \n', my_list, '\n\n'


# 2. using dictionary

dico = {'bugs':  'rabbit', 
        'elmer': 'human', 
        'wiley': 'coyote', 
        'tom':   'cat',
        'jerry': 'mouse'} 

ext = ['hops', 'walks', 'walks', 'schemes', 'scampers']

#dico['bugs'].append('hops')
print dico

for name, creature in dico.iteritems():
  print name, ' the ', creature

print '~~~some more work tbd here~~~\n'


s = '1,55,6,89,2|7,29,44,5,8|767,822,999'
ns = s.split('7,29')
print s
print ns
print ns[1][2]

print 'some more work tbd here~~~\n'


s = 'alberthwang-90,80,70,50|smadaan-99,80,70,90|satishm-90,90,90,90' 
ns = s.split('50')
print s
print ns
print 'tbd, use nesting~~~\n'

num_list = [5.2, 5.6, 5.1, 5.8, 5.9] 
num_list_rounded = map(round, num_list)
print num_list_rounded
print 'tbd, rounding function, map() (between 5-6)~~~\n'


print '\n~~~ ~~~ ~~~\n'


