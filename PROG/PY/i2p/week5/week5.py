#! /usr/bin/python
###### 1 (list by 2)

my_list = range(1,11)

for index, number in enumerate(my_list):
	if number % 2 == 0:
	 my_list[index] = number * 2

print my_list

#### 2
my_dict = {'bugs':'rabbit',
					 'elmer':'human',
					 'wiley':'coyote',
					 'tom': 'cat',
					 'jerry':'mouse'}

for cartoon, animal in my_dict.iteritems():
	if cartoon == 'bugs':
		print cartoon + ' the ' + animal + ' hopes'
	elif cartoon == 'elmer':
		print cartoon + ' the ' + animal + ' walks'
	elif cartoon == 'wiley':
		print cartoon + ' the ' + animal + ' walks'
	elif cartoon == 'tom':
		print cartoon + ' the ' + animal + ' schemes'
	elif cartoon == 'jerry':
		print cartoon + ' the ' + animal + ' scampers'


#### 3 

a = '1,55,6,89,2|7,29,44,5,8|767,822,999'
new_a = a.split('|')

def nested(z):
	y = z.split(',')
	return y
	

for x,y in enumerate(new_a):
	my_data = map(nested,new_a)
	
print my_data[1][2]


#### 4

my_string = 'alberthwang-90,80,70,50|smadaan-99,80,70,90|satishm-90,90,90,90'

new_string = my_string.split('|')
test_scores = {}

def nested2(z):
	y = z.split(',')
	return y

for x,y in enumerate(new_string):
	test_scores2 = map(nested2,new_string)

test_scores['alberthwang'] = test_scores2[0]
test_scores['smadaan'] = test_scores2[1]

print test_scores['smadaan'][2]

### 5 

num_list = [5.2, 5.6, 5.1, 5.8, 5.9]

def convert(x):
	if 5 < x <= 5.5:
		return 5
	elif 5.5 < x <= 6 :
		return 6
	else:
		return x
		
converted_list = map(convert,num_list)

print converted_list

### 6

text = 'the number is '

new_dict = {'1' : ', that is the best',
						'2' : ", that's is the type of pencil you use in SAT",
						'3' : ", that ryhmes with 'me'",
						'4' : ', I want some more',
						'5' : ', like a high-five!',
						'6' : ', what a neat trick...'}

for x,y in new_dict.iteritems():
	print text + x + y

### 7


str1 = 'ldap:alberthwang,eeid:67739|ldap:meng,eeid:107,building:CL5'

new_str1 = str1.split('|')

d = {}
d1 = {}
employees = []

for pair in new_str1[0].split(','):
	k,v = pair.split(':')
	d[k] = v
employees.append(d)

for pair in new_str1[1].split(','):
	k,v = pair.split(':')
	d1[k] = v
employees.append(d1)

print employees[1]['building']





	








