#!/usr/bin/python2.4 -tt
# Copyright 2008 Google Inc. All Rights Reserved.

"""Mimic pyquick exercise -- optional extra exercise.

Read in the file specified on the command line.
Do a naive split() on whitespace to obtain all the words in the file.
Rather than read the file line by line, it's easier to read
it into one giant string and split it once.

Build a "mimic" dict that maps each word that appears in the file
to a list of all the words that immediately follow that word in the file.
The list of words can be be in any order and should include
duplicates. So for example the key "and" might have the list
["then", "best", "then", "after", ...] listing
all the words which came after "and" in the text.
We'll say that the empty string is what comes before
the first word in the file.

With the mimic dict, it's fairly easy to emit random
text that mimics the original. Print a word, then look
up what words might come next and pick one at random as
the next work.
Use the empty string as the first word to prime things.
If we ever get stuck with a word that is not in the dict,
go back to the empty string to keep things moving.

Note: the module 'random' includes a random.choice(list)
method which picks a random element from a non-empty list.

For fun, feed your program to itself as input.
Could work on getting it to put in linebreaks around 70
columns, so the output looks better.

"""
__author__ = 'nparlante@google.com (Nick Parlante)'

import random
import sys


def MimicDict(filename):
  """Returns mimic dict mapping each word to list of words which follow it."""
  # +++your code here+++
  # LAB(begin solution)
  mimic_dict = {}
  f = open(filename, 'r')
  text = f.read()
  f.close()
  words = text.split()
  prev = ''
  for word in words:
    if not prev in mimic_dict: mimic_dict[prev] = [word]
    else: mimic_dict[prev].append(word)
    # Could write as: mimic_dict[prev] = mimic_dict.get(prev, []) + [word]
    # It's one line, but not totally satisfying.
    prev = word
  return mimic_dict
  # LAB(replace solution)
  # return None
  # LAB(end solution)


def Mimic(mimic_dict, word):
  """Given mimic dict and start word, prints 200 random words."""
  # +++your code here+++
  # LAB(begin solution)
  for unused_i in range(200):
    print word,
    nexts = mimic_dict.get(word)          # Returns None if not found
    if not nexts: nexts = mimic_dict['']  # Fallback to '' if not found
    word = random.choice(nexts)
  # The 'unused_' prefix turns off the lint warning about an unused variable.
  # LAB(replace solution)
  # print 'implement me'
  # LAB(end solution)


# Provided main(), calls MimicDict() and Mimic()
def main():
  if len(sys.argv) != 2:
    print 'usage:  mimic.py file-to-read'
    sys.exit(1)

  mimic_dict = MimicDict(sys.argv[1])
  Mimic(mimic_dict, '')


if __name__ == '__main__':
  main()
