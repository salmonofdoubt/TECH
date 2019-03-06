#! /usr/bin/python

employees = {}
d1 = {}
x = 0
def add_employee(ldap,name,title):    
  employees['name'] = name
  employees['title'] = title
  d1[ldap] = employees


x = 0

for x in range(5):
  to_do = raw_input('add or quit')
  if to_do == 'add':
    ldap = raw_input('employee LDAP: ')
    name = raw_input('employee name: ')
    title = raw_input('employee title: ')
    if ldap in d1:
      print ldap + 'already there'
    else:
      add_employee(ldap,name,title)
      employees = {}
      print ldap + ' has been added successfully'
    if x == 4:
      print 'Here are the employees records!'
      for x,y in d1.iteritems():
        print x + "'s name is " + d1[x]['name'] + 'and he/she is a ' + d1[x]['title']
  if to_do == 'quit':
    print 'Here are the employees records!'
    for x,y in d1.iteritems():
      print x + "'s name is " + d1[x]['name'] + ' and he/she is a ' + d1[x]['title']
    break




