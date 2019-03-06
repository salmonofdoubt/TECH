#!/usr/bin/python

import sys

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
    print 'usage: file.py {--count | --topcount} file'
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
