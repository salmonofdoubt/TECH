#! /usr/bin/python

class Employee():
  def __init__(self,ldap,name,location,salary,status):
    self.ldap = ldap
    self.name = name
    self.location = location
    self.salary = int(salary)
    self.status = status

  def Transfer(self):
    self.location = raw_input('enter new location: ')
  def Quit(self):
    self.status = 'INACTIVE'
  def Greet(self):
    print 'hi my name is ' + self.name + ' and I work at Google!'

class Manager(Employee):  	
	
  def get_employees(self,reportees):
    self.reportees = reportees
    for x in self.reportees:
      print x
	
  def num_reportees(self):
    print len(self.reportees)
	
  def locations(self,locations,NoDupLocations):
    self.locations = locations
    self.NoDupLocations = NoDupLocations
		
    for x in self.locations:
      if x not in self.NoDupLocations:
        self.NoDupLocations.append(x)
		
    print self.NoDupLocations

employee1 = Employee('jlan','peppo','dublin','100','active')

employee2 = Employee('mang','mario ng','dublin','200','active')

employee3 = Employee('mtony','mary tan','London','300','active')


reportees = [employee1.ldap, employee2.ldap, employee3.ldap]
locations = [employee1.location, employee2.location, employee3.location]
NoDupLocations = []

mymanager = Manager('bobo','bob martin','London','300','active')

employee1.Greet()
employee2.Greet()
employee3.Greet()

mymanager.Greet()
mymanager.get_employees(reportees)
mymanager.num_reportees()
mymanager.locations(locations,NoDupLocations)

employee1.Quit()
employee2.Quit()

print employee1.name + ' is ' + employee1.status
print employee2.name + ' is ' + employee2.status
