#!/usr/bin/python2.4
# Copyright 2008 Google Inc. All Rights Reserved.

"""YearNames exercise.

There is a wiki page which explains this exercise
http://wiki.corp.google.com/Codelab/PyQuickYearNames
(sometimes given out as a printout in class).

This is written as a standard python class, and
a google3 python class has a very similar structure.
The YearNames class encapsulates the data for one year of baby names.

-self.year is the int year
-self.name_rank is a dict maping string name to int rank

The method prototypes are provided. Fill in the needed code and
complete main() to call your code.

For writing regex, I like to include a copy of the target
text right next to my code for inspiration.

Here's what the html looks like in the baby.html files:
...
<h3 align="center">Popularity in 1990</h3>
....
<tr align="right"><td>1</td><td>Michael</td><td>Jessica</td>
<tr align="right"><td>2</td><td>Christopher</td><td>Ashley</td>
<tr align="right"><td>3</td><td>Matthew</td><td>Brittany</td>
...

"""

__author__ = 'nparlante@google.com (Nick Parlante)'

import re
import sys


class YearNames(object):
  """YearNames encapsulates the data for one year of baby names."""

  def __init__(self, filename):
    """Inits the instance by reading the given file (provided)."""
    self.year = 0
    self.name_ranks = {}
    self.ReadNames(filename)

  def GetYear(self):
    """Returns the int year for this data set (provided)."""
    return self.year

  def GetRank(self, name):
    """Returns int rank for name or 0 if name is not known."""
    # +++your code here+++
    return None

  def ReadNames(self, filename):
    """Reads the given file to set the year and name_ranks fields."""
    # +++your code here+++
    None # placeholder for your code

  def GetRanks(self):
    """Returns a list of (name, rank) tuples sorted by name."""
    # +++your code here+++
    return None

  def GetSummaryText(self):
    """Returns a text string summary with one line per name.

    The first line is the year and all the later lines are of the form
    "name<space>rank<newline>"
    sorted into increasing order by name."""
    # +++your code here+++
    return None


def main():
  # The command line argument code is provided.
  # Make a list of command line arguments, omitting the [0] element
  # which is the script itself.
  args = sys.argv[1:]
  if not args:
    print 'usage: yearnames.py [--summaryfile] file [file...]'
    sys.exit(1)

  # Notice the summary flag and remove it from args if it is present.
  summary = False
  if args[0] == '--summaryfile':
    summary = True
    del args[0]

  # +++your code here+++
  # For each filename, get the names, then either print its text summary
  # or write its summary file.

if __name__ == '__main__':
  main()
