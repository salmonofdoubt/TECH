#!/usr/bin/python2.6

data1 = [[1,2,3,78],
         [4,5,6,42],
         [7,8,9,90]]

data2 = [['albert', 'tom', 'sarahughes'],
         ['abe', 'abrahamlincoln', 'ac'],
         ['this is a random string', 'john', 'todd'],
         ['yu', 'chen', 'cheng']]

max_lenght = []


def display(x):
  for s in (x):
    lenght = len(max(s, key=len))
    max_lenght.append(lenght)
    final = max(max_lenght)
	
  for t,z in enumerate(x):         
    t = ' | '
    print ' +' + str(final * '=') + '+'
    print t,", ".join(map(str,z)).replace(',', '  |'), '| '
    print ' +' + str(final * '=') + '+'
    
    
    
table = display(data2)

print table


    
