#! /usr/bin/python

from animals import dog	
from animals import labrador

def main():
  my_dog = dog.Dog('Sonny','medium')
  my_labrador = labrador.Labrador('Larry','Large')
  print my_dog.Bark()
  print my_dog.Greet()
  print my_labrador.Bark()
  print my_labrador.Greet()

if __name__ == '__main__':
  main()
