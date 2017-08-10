#!/usr/bin/python2.4
#
# Copyright 2009 Google Inc. All Rights Reserved.

"""List machine names which are valid english words."""

# For example,
# the cluster YE has rack T whose machine number 1 spells the word "yeti".
# This exercise is aimed at those whose primary interest is in scripting
# and workflow automation through the use of existing google3 support tools.
# Such as HwOps techs.

# Get a list of data centers (which will be the first two letters of any word),
# use this to build a regular expression that recognizes valid rack names and
# names them as group member "rack" of the regular expression result dictionary.
# Use leet to translate the machine number into one or two look-alike letters,
# write a regex to only accept those leet-compatible letters as the name "num".
# Build a dictionary that converts one or two letter strings back to numbers,
# a regular expression object that finds consecutive rack and number regexes,
# then search through an english spelling dictionary for matching words.
# Assemble a mapping from the machine name back to the spelling from the file,
# and a list of all the rack names which were needed to express those machines.
# Finally, go back to the MDB and ask for all the machines on just those racks,
# and print out the machine and the word if it turns out to be a valid spelling.

# There should be about 600 results, actual count varies as production changes.

__author__ = "alexperry@google.com (Alex Perry)"

# http://www.python.org/doc/2.4/lib/module-re.html
import re

# http://wiki.corp.google.com/twiki/bin/view/Main/MdbAPIGuide
from google3.production.mdb import mdb_core
from google3.pyglib import app
from google3.pyglib import flags

FLAGS = flags.FLAGS

flags.DEFINE_string("dictionary",
                    "/usr/share/dict/american-english",
                    "A file of correctly spelled words, one per line")

flags.DEFINE_list("leet_map",
                  "0:od,1:li,2:z,3:e,4:ah,5:s,6:g,7:tl,8:b,9:p",
                  "mapping from digits to letters that look similar")


def BuildRacknameRe(unused_leet_digits):
  """Try to get a list of the data centers (first two letters of word)."""
  # Connect to the remote database
  # Assemble a single regex that matches only on valid data centers
  # Extract valid rack names as group member "rack"
  # Use informal leet transliteration to define a machine number
  # Combine the word and the number, with only whitespace to the end
  return "ye[a-z][li]\s?$"


def GetMachinesWithinRacks(unused_rack_names):
  """Convert a list of rack names into a list of machine names."""
  # Connect to the remote database
  # Tell it we want a list of all its machines
  # Restrict the answer to only a few of the racks
  return ["yet1", "yet2", "yet3"]


def main(unused_argv):
  # Convert the leet digits in the parameter into a dictionary
  # Figure out what letters each number could correspond to
  # Get the dictionary file, only keep words that could be a machine
  print "regex is", BuildRacknameRe({"1": "l"})
  # Get a list of all suitable machines in those racks
  print "not spellchecked machines", GetMachinesWithinRacks(["ye"])
  print "yet1", "yeti"

if __name__ == "__main__":
  app.run()
