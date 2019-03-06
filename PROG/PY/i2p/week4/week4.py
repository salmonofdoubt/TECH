#!/usr/bin/python

#Part 1 -Data structures

index = ['albert','angela','leo','bridget']
print index

for name in range (0,len(index),1):
  index[name] = index[name].upper()
  index[name] = index[name].replace('A','a')
print index

index[0] = index[0] + ' hwang'
index[1] = index[1] + ' ellington'
index[2] = index[2] + ' chau'
index[3] = index[3] + ' campbell'
print index

index2 = list(index)

for name in range (0,len(index2),1):
  index2[name] = index2[name].lower()
  index2[name] = index2[name].replace(' ','')

names2 = zip(index2, index)
names2_dict = dict(names2)

print names2_dict

#Part 2 -Data structures (again)

data = []
summary = {}

total_ints = int(raw_input('Total integers in data: '))
count = 0

while count < total_ints:
  user = int(raw_input('Enter an integer: '))
  data.append(user)
  count += 1

data_odd = []
for x in data:
  if x % 2 == 1:
    data_odd.append(x)

# sorting data for getting highest, lowest integer
data.sort()
data_odd.sort()

# sum of integers
num = 0
for x in data:
  num += int(x)


summary['sum'] =str(num) 
summary['max'] =str( data[-1:]).strip('[]')
summary['max_odd'] =str( data_odd[-1:]).strip('[]')

print 'The sum of all the data is: ' + summary['sum']
print 'The max int is: ' + summary['max']
print 'The max odd int is: ' + summary['max_odd']

# Part 3 - Functions

def convert(yards):
  feet = str(yards * 3) + ' feet'
  return feet

distances = [32, 56, 111, 100,300,400]
list2 = []

for num in distances:
  list2.append(convert(num))
  distances = list2
print distances



















