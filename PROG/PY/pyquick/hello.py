#!/usr/bin/python2.4 -tt
# Copyright 2008 Google Inc. All Rights Reserved.

"""A tiny Python program to check that Python is working.

1. Create a directory for the PyQuick course and copy this hello.py file
to your directory. Go to (cd) into that directory and type in the following
command to run the hello.py program:
python hello.py
That should print: Hello World

Type in this command to run the hello.py script, passing it an argument:
python hello.py "woo hoo"
that should print: Hello woo hoo

2. Try editing the code below, changing the string 'Hello' to 'Howdy',
and check that you can save and run the program and see the new output.
Once you have that working, you're ready for class -- you can edit
and run Python code; now you just need to learn Python!
"""

import sys


# Define a main() function that prints a little greeting.
def main():
  # Get the name from the command line, using 'World' as a fallback.
  if len(sys.argv) == 2:
    name = sys.argv[1]
  else:
    name = 'World'
  print 'Hello ' + name

# This is the standard boilerplate that calls the main() function.
if __name__ == '__main__':
  main()
