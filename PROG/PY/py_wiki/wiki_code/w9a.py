#!/usr/bin/env python
#9_ForLoops

print('1. simple for loops\n')
count_number = range(1,5)       #range uses start, finish
for count in count_number:
    print(count)
print('\n or \n')
for count in range(1,5):
    print(count)
print('\n')

demolist = ['life', 42, 'the universe', 6, 'and', 7, 'everything']
for item in demolist:
    print(item)
print('\n')

list = [2, 4, 6, 8]
sum = 0
for num in list:
    sum = sum + num
print("2. The sum is:", sum, '\n')

print('3. Find dup in list\n')
list = [4, 5, 7, 8, 9, 1, 0, 7, 10]
print('raw list   :', list)
list.sort()
print('sorted list:',list)
prev = list[0]
del list[0]
for item in list:
    if prev == item:
        print("Duplicate of", prev, "found\n")
    prev = item          

print('4. Debug someting')
input("")
l = [4, 5, 7, 8, 9, 1, 0, 7, 10]
print("l = [4, 5, 7, 8, 9, 1, 0, 7, 10]", "\t\tl:", l)
l.sort()
print("l.sort()", "\t\tl:", l)
prev = l[0]
print("prev = l[0]", "\t\tprev:", prev)
del l[0]
print("del l[0]", "\t\tl:", l)
for item in l:
    if prev == item:
        print("Duplicate of", prev, "found")
    print("if prev == item:", "\t\tprev:", prev, "\titem:", item)
    prev = item
    print("prev = item", "\t\tprev:", prev, "\titem:", item)
    
