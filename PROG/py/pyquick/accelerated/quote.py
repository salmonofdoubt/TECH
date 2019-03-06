#!/usr/bin/python2.4
# Copyright 2008 Google Inc. All Rights Reserved.
#

"""Contains a main() which uses the Quote class."""

__author__ = 'nparlante@google.com (Nick Parlante)'

# (The BUILD dependency for these modules is '//pyglib')
from google3.pyglib import app
from google3.pyglib import flags
from google3.pyglib import logging

# Import Quote class
# Note that our full package is spelled out.
from google3.codelab.pyquick.accelerated import quote_lib


# Register our flag definitions
flags.DEFINE_string('quote_text', "It's pythonic!", 'text of quote')
flags.DEFINE_string('quote_author', 'python', 'author of quote')
flags.DEFINE_string('write_file', '', 'write to this file')
flags.DEFINE_string('read_file', '', 'read from this file')
flags.DEFINE_boolean('sense_of_humor', False, 'demonstrates a boolean flag')
flags.DEFINE_integer('counter', 100, 'demonstrates an int flag')


# Set global FLAGS variable to hold flags, so it looks just
# like C++ code.
FLAGS = flags.FLAGS


def main(unused_args):
  logging.info('quote main()')

  # Loggging/exit for scary case
  if 'religion' in FLAGS.quote_text: logging.fatal('religion in quote!')

  # Create quote object based on the flags
  quote = quote_lib.Quote(FLAGS.quote_text, FLAGS.quote_author)

  # Write or read the quote object with the filesystem if flags indicate.
  if FLAGS.write_file:
    quote.WriteShirt(FLAGS.write_file)

  if FLAGS.read_file:
    quote.ReadShirt(FLAGS.read_file)

  # In any case, print the quote to stdout
  print quote.GetFormatted(),


# Here app.run() is google3 code to do basic setup, parse flags, and then
# call back to our main() above.
if __name__ == '__main__':
  app.run()
