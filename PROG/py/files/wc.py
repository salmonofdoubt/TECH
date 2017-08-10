#!/usr/bin/python -tt

"""
Workflow: don't build the whole program at once. Get it to an intermediate milestone and print your data structure and sys.exit(0). When that's working, try for the next milestone. Optional: define a helper function to avoid code duplication inside
print_words() and print_top().
"""

import sys, string

# 1.2. --count  --topcount
def count_aux(filename):
  mapping = {}                  #to map each word to its count
  curr = open(filename, 'r')
  
  for line in curr:             
    splitted = line.split()     #split become the splitted items 
  
    for e in splitted:          #for element in split
      low = e.lower()           #make it lower
  
      if low not in mapping:        
         mapping[low] = 1       #word occurs for the first time.
      else:
        mapping[low] = mapping[low] + 1
  curr.close()                  #good form.
  print 'mapping:\n', mapping
  return mapping

# 1.1. --count
def print_words(filename):
  mapping = count_aux(filename)   #just obtaining the return value count_aux()
  words = sorted(mapping.keys())  #words is mapping but sorted accord to its keys
  for w in words:                 
    print w, mapping[w]
    

# 2.2. --topcount    
def get_count(word_count_tuple):
  return word_count_tuple[1]

# 2.1. --topcount
def print_top(filename):
  mapping = count_aux(filename)   #just obtaining the return value count_aux()
  items = sorted(mapping.items(), key=get_count, reverse=True)
  for item in items[:20]:
    print item[0], item[1]


#==============================================================================
# calls the print_words() and print_top() functions which you must define.
def main():
  if len(sys.argv) != 3:
    print 'usage: ./wordcount.py {--count || --topcount} file'
    sys.exit(1)

  
  option = sys.argv[1]
  filename = sys.argv[2]
  
  if option == '--count':
    print_words(filename)
  elif option == '--topcount':
    print_top(filename)
  else:
    print 'unknown option: ' + option
    sys.exit(1)

if __name__ == '__main__':
  main()
