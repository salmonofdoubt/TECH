#!/usr/bin/env python
# encoding: utf-8
"""
Discription: More on classes

|----------------|
| Class | Object |
| has-a	|	is-a   |
|----------------|

Created by André Baumann 2012 Copyright (c) Google Inc. 2012. All rights reserved.
"""
## Animal inherits from object, is-a object
class Animal(object):
	pass

## Dog inherits from Animal
class Dog(Animal):
	def __init__(self, name):
		## dog has-a name
		self.name = name

## Cat inherits from animal, is-a animal
class Cat(Animal):
	def __init__(self, name):
		## ??
		self.name = name

## Person inherits from object, is-a object
class Person(object):
	def __init__(self, name):
		## Person has-a name
		self.name = name
		## Person has-a pet (of some kind)
		self.pet = None

## Employee inherits from Person, is-a Person
class Employee(Person):
	def __init__(self, name, salary):
		## Employee has-a name but from super class, I suppose
		super(Employee, self).__init__(name)
		## Employee has-a salary
		self.salary = salary

## Fish inherits from object, is-a object
class Fish(object):
	pass

## Salmon inherits from Fish, is-a Fish
class Salmon(Fish):
	pass

## Halibut inherits from Fish, is-a Fish
class Halibut(Fish):
	pass

## rover is-a Dog
rover = Dog("Rover")
## satan is-a Cat
satan = Cat("Satan")
## mary is-a Person
mary = Person("Mary")
## Mary's pet is-a satan
mary.pet = satan
## Frank is-a Employee, calling Employee with attributes
frank = Employee("Frank", 120000)
## Frank's pet is-a rover
frank.pet = rover
## flipper is-a fish
flipper = Fish()
## crouse is-a salmon
crouse = Salmon()
## harry is-a halibut
harry = Halibut()


def main():
	pass
if __name__ == '__main__':
	main()
