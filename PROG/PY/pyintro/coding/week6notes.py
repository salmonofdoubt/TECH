#!/usr/bin/python2.4 -tt
#W6NOTES OOO

# creating a class, TEMPLATE OF OBJECT
class Dog(object):

# __init__ is reserved constructor method, defines how an object must be created
# 1st parameter always 'SELF', placeholder, so 2 parameters here (name, size)
  def __init__(self, name, size):
    self.name = name
    self.size = size

#a couple of methods
  def Defecate(self):
    print 'bloop bloop!'
  def Bark(self):
    print 'bark bark!'

#creating Dog object my_dog, INSTANTIATION
my_dog = Dog('Scooter', 'Labrador')    
#print my_dog.name
#print my_dog.size

#stick the object, that was created according to class template, through some functions
my_dog.Defecate()                       
my_dog.Bark()


#here is another class, encapsulating the previous
class GermanShepard(Dog):
  def Bark(self):
    print 'Shephard bark!'

#instantiate object
my_german = GermanShepard('Attacker', 'Big')

#stick this object through some methods ALSO of the previous class
my_german.Defecate()
my_german.Bark()


print '\n\n~~~~'

