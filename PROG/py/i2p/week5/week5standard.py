#! /usr/bin/python

emp_number = range(0,3)
employees = []
d = {}

for x in emp_number:
  ldap = raw_input('ldap: ')
  name = raw_input('name: ')
  title = raw_input('title: ')
  d['title'] = title
  d['name'] = name
  d['ldap'] = ldap
  employees.append(d)
  d = {}

print 'Here are the employees records!'
number = 1

for x in employees:
  print 'Employee number - ' + str(number)+ '\n' + x['name'] + "'s LDAP is " + x['ldap'] + ' and he/she is a ' + x['title']
  number += 1





