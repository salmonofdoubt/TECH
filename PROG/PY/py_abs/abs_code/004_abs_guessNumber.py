#!/usr/bin/env python
  
import random
print('Guess my numner (between 1..100) as swiftly as possible')

rand = random.randint(1,100)
guess = int(input('Make a guess: '))
tries = 1

while guess != rand:
    if guess > rand:
        print('Lower...')
    else:
        print('Higher')
    guess = int(input('Make a guess: '))
    tries += 1

print('Right! You needed', tries, 'tries to figure it out')
input('\nexit')








