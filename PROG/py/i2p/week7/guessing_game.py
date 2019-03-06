#! /usr/bin/python

import random

def main():
  lowest_int = int(raw_input('enter lowest integer: '))
  highest_int = int(raw_input('enter highest integer: '))
  right_number = random.randint(lowest_int,highest_int)
  for num in range(5):
    user_guess = int(raw_input('enter your guess: '))
    if user_guess == right_number:
      print 'CONGRATULATIONS, THE NUMBER WAS ' + str(right_number)
      break	
    if num == 4:
      print 'WA..WAAAA..THE NUMBER WAS ' + str(right_number)

if __name__ == '__main__':
	main()
