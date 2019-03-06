#!/usr/bin/env python
# encoding: utf-8
"""
Discription: remake of dict exercise 41, using classes.
Created by André Baumann 2012 Copyright (c) Google Inc. 2012. All rights reserved.
"""

from sys import exit
from random import randint

class Game(object):
	def __init__(self, start):
		self.quips = ["1", "2", "3", "4"]
		self.start = start

	def play(self):
		next = self.start
		while True:
			print "\n--------"
			room = getattr(self, next)
			next = room()

	def death(self):
		print self.quips[randint(0, len(self.quips)-1)]
		exit(1)

	def central_corridor(self):
		print "---central_corridor--- (*joke, shoot, dodge)"
		
		action = raw_input("> ")
		
		if action == "shoot":
			return 'death'
		
		elif action == "dodge":
			return 'death'
			
		elif action == "joke":
			return 'laser_weapon_armory'
		else:
			print "DOES NOT COMPUTE!"
			return 'central_corridor'
			
	def laser_weapon_armory(self):
		print "---laser_weapon_armory--- (digit)"
		
		code = "%d" %randint(1,9)
		guess = raw_input("[keypad]> ")
		guesses = 0
		
		while guess != code and guesses < 10:
			print "incorrect!"
			guesses += 1
			guess = raw_input("[keypad]> ")

		if guess == code:
			return 'the_bridge'
		else:
			return 'death'
	
	def the_bridge(self):
		print "---the_bridge--- (*place throw)"
		action = raw_input("> ")
		if action == "throw":
			return 'death'
		
		elif action == "place":
			return 'escape_pod'
		
		else:
			print "DOES NOT COMPUTE!"
			return "the_bridge"
		
	def escape_pod(self):
		print "---escape_pod (1-5)"
		
		good_pod = randint(1,5)
		guess = raw_input("[pod #]> ")
		
		if int(guess) != good_pod:
			return 'death'
		else:
			print "You won!"
			exit(0)
			
a_game = Game("central_corridor")
a_game.play()									# 1. start, calls central_corridor() and puts it  
															#    through play() 

def main():
	pass
if __name__ == '__main__':
	main()
