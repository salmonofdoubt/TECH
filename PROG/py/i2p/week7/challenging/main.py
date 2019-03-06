from animals import dog2
from animals import labrador2

def main():
	my_dog = dog2.Dog2('Sonny','super big')
	my_labrador = labrador2.Labrador2('Larry','large')
	print my_dog.Bark()
	print my_dog.Greet()
	print my_labrador.Bark()
	print my_labrador.Greet()

if __name__ == '__main__':
  main()
