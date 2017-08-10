#!/usr/bin/env python
#8_Lists


demolist = ['life', 42, 'the universe', 6, 'and', 7] ##words must be put in _''_
print("demolist = ",demolist, '\n')

demolist.append("everything")
print('appended \'everything\'') 
print('demolist = ',demolist, '\n')

del demolist[2] 
print('remove \'the universe\'')
print('demolist = ',demolist, '\n')


print("len(demolist) =", len(demolist))
print("demolist.index(42) =", demolist.index(42))
print("demolist[1] =", demolist[1], '\n')


# Next, loop through the list
if "life" in demolist:
    print("'life' was found in demolist")
else:
    print("'life' was not found in demolist")
 
if "amoeba" in demolist:
    print("'amoeba' was found in demolist")
 
if "amoeba" not in demolist:
    print("'amoeba' was not found in demolist")

demolist.append("amoeba")
print('\nappended \'amoeba\'') 
print('demolist = ',demolist, '\n')

if "amoeba" in demolist:
    print('\'amoeba\' was now found in demolist')
 
if "amoeba" not in demolist:
    print("'amoeba' was not found in demolist")

print('\n\n\t\tthis was a very primitive program... ')
