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
    # LAB(begin solution)
    return self.name_ranks.get(name, 0)
    # LAB(replace solution)
    # return None
    # LAB(end solution)

  def ReadNames(self, filename):
    """Reads the given file to set the year and name_ranks fields."""
    # +++your code here+++
    # LAB(begin solution)
    f = open(filename, 'r')
    text = f.read()
    f.close()
    # Could process the file line-by-line, but regex on the whole text
    # at once is even easier.

    # Get the year
    year_match = re.search(r'Popularity\s+in\s+(\d\d\d\d)', text)
    assert year_match
    year = year_match.group(1)
    self.year = int(year)  # note string/int conversion

    # Extract all the data tuples with a findall()
    # each tuple is: (rank, boy-name, girl-name)
    tuples = re.findall(r'<td>(\d+)</td><td>(\w+)</td>\<td>(\w+)</td>', text)
    #print tuples

    # Store data into a dict using each name as a key and that
    # name's int rank as the value.
    # Only store if the name is not already in the dict,
    # so lower ranks are not overwritten by higher ranks.
    self.name_ranks.clear()
    for t in tuples:
      self.name_ranks.setdefault(t[1], int(t[0]))
      self.name_ranks.setdefault(t[2], int(t[0]))
      # d.setdefault(k, v) sets the value only if key is not already set.
    # LAB(replace solution)
    # None # placeholder for your code
    # LAB(end solution)

  def GetRanks(self):
    """Returns a list of (name, rank) tuples sorted by name."""
    # +++your code here+++
    # LAB(begin solution)
    # This does it very compactly.
    return sorted(self.name_ranks.items())
    # More spelled out version:
    # [(name, self.name_ranks[name]) for name in sorted(self.name_ranks.keys())]
    # LAB(replace solution)
    # return None
    # LAB(end solution)

  def GetSummaryText(self):
    """Returns a text string summary with one line per name.

    The first line is the year and all the later lines are of the form
    "name<space>rank<newline>"
    sorted into increasing order by name."""
    # +++your code here+++
    # LAB(begin solution)
    return ('%d\n' % self.GetYear() +
            ''.join(['%s %s\n' % name_rank for name_rank in self.GetRanks()]))
    # LAB(replace solution)
    # return None
    # LAB(end solution)


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
  # LAB(begin solution)
  for filename in args:
    year_names = YearNames(filename)
    text = year_names.GetSummaryText()

    if summary:
      f = open(filename + '.summary', 'w')
      f.write(text)
      f.close()
    else:
      print text,
      # Alternately, could sys.stdout.write(text)
  # LAB(end solution)

if __name__ == '__main__':
  main()
