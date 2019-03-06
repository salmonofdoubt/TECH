#! /usr/bin/python

import random

class GuessingGame:	
  def __init__(self,max_int,min_int,target_int,total_guesses):
    self.max_int = max_int
    self.min_int = min_int
    self.target_int = random.randint(min_int,max_int)
    self.total_guesses = total_guesses
		
  def Guessint(self,user_guess):
    for x in range(self.total_guesses):
      self.user_guess = int(raw_input('enter a number: '))
      if self.user_guess == self.target_int:
        break

  def Congratulate(self):
    print 'CONGRATULATIONS, THE NUMBER WAS ' + str(self.target_int)
			
  def ShowFailedMsg(self):
    print 'WA..WAAAA..THE NUMBER WAS ' + str(self.target_int )
	
	
