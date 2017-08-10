#!/usr/bin/env python
# encoding: utf-8
"""
Discription: 
Created by André Baumann 2012 Copyright (c) Google Inc. 2012. All rights reserved.
"""
from sys import exit
from random import randint

def death():												# --------- 7. -----------
	quips = ["You died. You kinda suck at this.",
	"Nice job, you died ...jackass.",
	"Such a luser.",
	"I have a small puppy that's better at this."]
	print quips[randint(0, len(quips)-1)]
	exit(1)


def central_corridor():							# --------- 3. -----------
	print "CENTRAL_CORRIDOR (*joke dodge shoot)"
	
	action = raw_input("> ")
	
	if action == "shoot":
		return 'death'
	elif action == "dodge":
		return 'death'		
	elif action == "joke":
		return 'laser_weapon_armory'		# --------- 4. -----------
		
	else:
		print "DOES NOT COMPUTE..."
		return 'central_corridor'

def laser_weapon_armory():
	print "LASER_WEAPON_ARMORY (a digit)"
	
	code = "%d" %randint(1,9)
	guess = raw_input("[keypad]> ")
	guesses = 0
	
	while guess != code and guesses < 10:
		print "BZZZZEDDD!"
		guesses += 1
		guess = raw_input("[keypad]> ")
		
	if guess == code:
		print "PASS"
		return 'the_bridge'							# --------- 5. -----------
		
	else:
		return 'death'

def the_bridge():
	print "THE_BRIDGE (place)"
	
	action = raw_input("> ")
	
	if action != "place":
		return 'death'									# --------- 7. -----------
	elif action == "place":
		return 'escape_pod'							# --------- 6. -----------
	
	else:
		print "DOES NOT COMPUTE!"
		return 'the_bridge'

def escape_pod():
	print "ESCAPE_POD"
	
	good_pod = randint(1,5)
	guess = raw_input("[pod #]> ")
	
	if int(guess) != good_pod:
		print "crushing your body into jam jelly."
		return 'death'									# --------- 7. -----------
	else:
		print "You escaped, You won!"
		exit(0)
		
ROOMS = {														# dict used to call functions
	'death': death,
	'central_corridor': central_corridor,
	'laser_weapon_armory': laser_weapon_armory,
	'the_bridge': the_bridge,
	'escape_pod': escape_pod
}

def runner(map, start):						# --------- 2. -----------
	next = start
	while True:
		room = map[next]
		print "\n--------"
		next = room()

runner(ROOMS, 'central_corridor')	# --------- 1. -----------

def main():
	pass
if __name__ == '__main__':
	main()
