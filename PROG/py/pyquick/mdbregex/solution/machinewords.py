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


def BuildRacknameRe(leet_digits):
  """Try to get a list of the data centers (first two letters of word)."""
  # Get a handle to the connection to the remote machine database
  # Use a read_only connection unless you are making changes to the database.
  mdb = mdb_core.RemoteMachineDatabase(read_only=True)
  mdbh = mdb.Connect()
  # Here is a regex that we could use if we don't look in the MDB
  datacenters_re = "[a-z]{2}"
  try:
    # Define our request for all the data centers, without any filter
    query_op = mdb_core.ListDatacenters(mdb)
    # Get the list of results, each record describes a single database
    datacenters = query_op.Retrieve(mdbh)
    # The record exposes every column as a named property, we want "value"
    datacenters = [d.value for d in datacenters]
    # Convert the list of two letter codes into a regular expression
    datacenters_re = "(" + "|".join(datacenters) + ")"
  finally:
    # The docs ask us not to leave handles lying around open and used
    mdbh.Close()
  # Extract valid rack names as group member "rack"
  rackname_re = datacenters_re + "[a-z]{1,2}"
  rackname_re = "(?P<rack>" + rackname_re + ")"
  # Use informal leet transliteration to define a machine number
  leet_digit_re = "[" + "".join(leet_digits.values()) + "]"
  leet_digit_re += "{1,2}"
  # Extract the machine number as group member "num" in the result
  machnumber_re = "(?P<num>" + leet_digit_re + ")"
  # Combine the word and the number, with only whitespace to the end
  return rackname_re + machnumber_re + "\s?$"


def GetMachinesWithinRacks(rack_names):
  """Convert a list of rack names into a list of machine names."""
  mdb = mdb_core.RemoteMachineDatabase(read_only=True)
  mdbh = mdb.Connect()
  machine_names = []
  try:
    query_op = mdb_core.ListMachines(mdb)
    query_op.SetRacks(rack_names)
    machine_names = [r.machine_name for r in query_op.Retrieve(mdbh)]
  finally:
    mdbh.Close()
  return machine_names


def main(unused_argv):
  # Convert the leet digits in the parameter into a dictionary
  leet_digits = dict([(item[0], item[2:]) for item in FLAGS.leet_map])
  # Figure out what letters each number could correspond to
  leet_letters = {}
  for digit, letters in leet_digits.items():
    for letter in letters:
      leet_letters[letter] = digit
      for digit2, letters2 in leet_digits.items():
        for letter2 in letters2:
          leet_letters[letter + letter2] = digit + digit2
  # The dictionary uses mixed cased to indicate mandatory capitalization,
  # so we compile the regex insisting on case insensitive comparison.
  machine_re = re.compile(BuildRacknameRe(leet_digits), re.IGNORECASE)
  # We want both all the valid words in the dictionary and all racks
  spellings = {}
  racks = []
  # Get the dictionary file, default iterator conveniently gets one line
  for word in open(FLAGS.dictionary):
    # Apply the regex; we only process the result if it matches
    matched = machine_re.match(word)
    if matched:
      # Force the two parts we care about to lower case
      digits = leet_letters[matched.group("num").lower()]
      rack = matched.group("rack").lower()
      # Accumulate rack names and words
      if not rack in racks:
        racks.append(rack)
      spellings[rack + digits] = rack + matched.group("num").lower()
  # Get a list of all machines in those racks
  for machine in GetMachinesWithinRacks(racks):
    if machine in spellings:
      print machine, spellings[machine]

if __name__ == "__main__":
  app.run()
