#!/usr/bin/python2.4 -tt
#W6HOMEWORK1 OOO
from pprint import pprint

# PART 2
class CashRegister(object):
  def __init__(self, name, total_cash, amount_last, no_trans):
		self.name = name
		self.total_cash = total_cash
		self.amount_last = amount_last
		self.no_trans = no_trans
	
  def Transact(self):
		register = int(raw_input('Enter new amount:' ))
		'''summ =+ register'''
		print register

	
'''
  def MakeChange(self):
	
  def EmptyOut(self):

  def ShowLast(self):

  def ClearHistory(self):
'''
my_money = CashRegister(name 				= 'Andre',
												total_cash 	= 'zero',
												amount_last = 'zero',
												no_trans 		= 'zero')

my_money.Transact()

'''

'\n\n===========END CASHREGISTER====================\n\n'

# PART 1
class Cat(object):
  def __init__(self, name, furcolor, temper):
	self.name = name
	self.furcolor = furcolor
	self.temper = int(temper)

  def Pur(self):
	print 'purrr!\n\n'

  def Temperament(self):
	temper = int(raw_input('what is the cat\'s temper:' ))
	if temper >= 5:
	  print '(>= 5) uhh, it\'s an angry cat'
	elif temper < 5 and temper >= 2:
	  print '(< 5 and >= 2) ok, pretty normal cat'
	elif temper < 2:
	  print '(< 2) quite a mellow cat'


my_cat = Cat(name			= 'Garfield',
			 			furcolor  = 'Orange',
			 			temper	  =  10)

# print the entire object :)
print vars(my_cat)

# stick object through a few methods
my_cat.Pur()
my_cat.Temperament()
print '\n\n=========END CAT================================\n\n'


# PREVIOUS SAMPLE WORKING
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

#instantiate a German object
my_german = GermanShepard('Attacker', 'Big')

#stick this object through some methods ALSO of the previous class
my_german.Defecate()
my_german.Bark()
print '\n\n=======END DOG================================='

'''

