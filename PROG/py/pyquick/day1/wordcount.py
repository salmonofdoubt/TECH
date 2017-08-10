#!/usr/bin/python2.4 -tt
# Copyright 2008 Google Inc. All Rights Reserved.

"""WordCount pyquick exercise.

The main() below is already defined and complete. It calls Count()
and TopCount() functions which you write.

1. For the --count flag, implement a Count(filename) function that counts
how often each word appears in the text and prints:
word1 count1
word2 count2
...

Print the above list in order sorted by word (python will sort punctuation to
come before letters -- that's fine). Store all the words as lowercase,
so 'The' and 'the' count as the same word.

2. For the --topcount flag, implement a TopCount(filename) which is similar
to Count() but which prints just the top 20 most common words sorted
so the most common word is first, then the next most common, and so on.

Use str.split() (no arguments) to split on all whitespace.

Workflow: don't build the whole program at once. Get it to an intermediate
milestone and print your data structure and sys.exit(0).
When that's working, try for the next milestone.

Optional: define a helper function to avoid code duplication inside
Count() and TopCount().

"""
__author__ = 'nparlante@google.com (Nick Parlante)'

import sys

# +++your code here+++
# Define Count(filename) and TopCount(filename) functions
# LAB(begin solution)


def WordCountDict(filename):
  # Returns a word/count dict for this filename.
  # Utility used by Count() and TopCount().
  word_count = {}                 # dict, maps each word to its count
  input_file = open(filename, 'r')
  for line in input_file:
    words = line.split()          # make a line out of input_file
    for word in words:
      word = word.lower()         # all results lower case
      if not word in word_count:
        word_count[word] = 1
      else:
        word_count[word] = word_count[word] + 1
  input_file.close()              #good form
  return word_count

def Count(filename):
  # Prints one per line '<word> <count>' sorted by word for the given file
  word_count = WordCountDict(filename)
  words = sorted(word_count.keys())
  for word in words:
    print word, word_count[word]

def GetCount(word_count_tuple):
  # Returns the count from a dict word/count tuple  -- used for custom sort.
  return word_count_tuple[1]

def TopCount(filename):
  # Prints the top count listing for the given file.
  word_count = WordCountDict(filename)

  # Each item is a (word, count) tuple.
  # Sort them so the big counts are first using key=GetCount() to extract count.
  items = sorted(word_count.items(), key=GetCount, reverse=True)

  # Print the first 20
  for item in items[:20]:
    print item[0], item[1]
# LAB(end solution)


# ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
# This main() command line argument parsing is provided and
# calls the Count() and TopCount() functions which you must define.
def main():
  if len(sys.argv) != 3:
    print 'usage: wordcount.py {--count | --topcount} file'
    sys.exit(1)

  option = sys.argv[1]
  filename = sys.argv[2]
  if option == '--count':
    Count(filename)
  elif option == '--topcount':
    TopCount(filename)
  else:
    print 'unknown option: ' + option
    sys.exit(1)

if __name__ == '__main__':
  main()
