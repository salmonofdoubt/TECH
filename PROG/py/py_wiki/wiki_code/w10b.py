#!/usr/bin/env python
#10_Boolean



list = ['Life', 'The Universe', 'Everything', 'Jack', 'Jill', 'Life', 'Jill', 'Life']
copy = list[:]          #copies the outer list, not sure why it's done here, no inner list afaics
#print(list)
#print(copy)

copy.sort()
prev = copy[0]
del copy[0]

count = 0

while count < len(copy) and copy[count] != prev:
    prev = copy[count]
    count = count + 1

if count < len(copy):
    print("First match:", prev)
