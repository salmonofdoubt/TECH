#!/usr/bin/python2.4 -tt

count = 0
my_list = ['albert', 'angela', 'leo', 'bridget']
print my_list
for x in my_list:
  if x is not 'a':
    my_list[count] = x.upper()
    count += 1
print my_list, '\n***NEEDS*WORK***\n'

surname = ['hwang', 'ellington', 'chau', 'campbell']
my_list.insert(1, 'hwang')
my_list.insert(3, 'ellington')
my_list.insert(5, 'chau')
my_list.insert(7, 'campbell')
print my_list, '\n~~~\n'



def ConvertToFeet(yards):
  conv = yards*3
  return str(conv)

distance = 42
#for i in range(0, len(distance), 1):
feet = ConvertToFeet(distance)
print 'distance (m):  ' + str(distance)
print 'distance (ft): ' + str(feet)
print '***NEEDS*WORK***\n'



data = []
summary = {}

i = 1
total_ints = int(raw_input('Enter total number of integers to record: '))
while i <= total_ints:
  num = int(raw_input('Enter an integer: '))
  data.append(num)
  i += 1
print data

# summ=sum(data)
# maxx=max(data)
# print 'The sum of all the data is: ' + summ
# print 'The max int is: ' + maxx





