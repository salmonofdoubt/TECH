#!/usr/bin/env python
#8_Lists

demolist = ['life', 42, 'the universe', 6, 'and', 7] ##words must be put in _''_
print("demolist = ",demolist)
demolist.append("everything")
print('appended \'everything\'') 
print('demolist = ',demolist, '\n')

##create variable c, start at 0,
##increment until last index of list.
##Print each element of the list'''
for c in range(len(demolist)):
    print('demolist[', c, '] =', demolist[c])
print('\n')

##remove given element
del demolist[2] 
print('remove \'the universe\'')
print('demolist = ',demolist, '\n')

##much better way to create c
for c, x in enumerate(demolist):
    print("demolist[", c, "] =", x)



    
