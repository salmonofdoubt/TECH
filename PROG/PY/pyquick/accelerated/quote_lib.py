#!/usr/bin/python2.4
# Copyright 2008 Google Inc. All Rights Reserved.

"""A simple Quote class demonstrating google3 integration."""

__author__ = 'nparlante@google.com (Nick Parlante)'

# Import pywrapfile, the "wrapped" python version of the
# google3 C++ File class in file/base/file.h
from google3.file.base import pywrapfile


# Suppose there is a binky.proto file somewhere, built as a binky_proto library.
# To use it the BUILD dependency is the same as for any language:
#   deps = [ "//foo/bar:binky_proto",  ]
# In the client python code 'binky_pb' is the auto-generated module name
# corresponding to binky.proto, imported like this:
#   from foo.bar import binky_pb
# Thereafter, refer to protocol buffers in the library as binky_pb.Foo

# Import the protocol buffer library shwag_proto.
# Here schwag_pb is the auto generated python module name corresponding
# to schwag_proto.
from google3.codelab.pyquick.accelerated import schwag_pb


class Quote(object):
  """The Quote class encapsulates a quote text and author."""

  def __init__(self, text, author):
    self.text = text
    self.author = author
    self.funny = False  # setting an ivar causes it to exist

  def GetText(self):
    """Returns the text of the quote."""
    return self.text

  def SetText(self, text):
    """Sets the text of the quote.

    Args:
      text: the new text value
    """
    self.text = text

  def GetFormatted(self):
    """Returns a formatted text form of the quote."""
    return '%s\n--%s\n' % (self.text, self.author)

  # The schwag_pb python module contains the 'shirt' protocol buffer which
  # contains the 'text' and 'project' data fields for a google shirt.
  # There are standard protocol buffer methods for each field:
  #  shirt = schwag_pb.Shirt()  // Creates empty protocol buffer object
  #  shirt.author()             // Retrieves author field
  #  shirt.set_author(str)      // Sets author field
  #  shirt.has_author()         // Tests if author field is set

  # Here ReadShirt() and WriteShirt() call google3 code to read and write
  # between a python Quote object and a shirt protocol buffer stored in
  # the file system.

  def ReadShirt(self, filename):
    """Reads a shirt protocol buffer from the file and inits self with the data.

    Args:
      filename: file containing shirt protocol buffer
    """
    # The C++ File class includes a static method called
    # ReadFileToStringOrDie() which is translated to appear
    # inside the pywrapfile module. Here 'buff' is not unicode
    # decoded or anything; it's just bytes.
    buff = pywrapfile.File.ReadFileToStringOrDie(filename)

    # Errors: Note that if a call such as above fails internally with,
    # say, a CHECK exception, it will terminate the program with a
    # standard C++ stack trace, never getting back to your python code.

    # Construct a shirt protocol buffer object based on the bytes
    # from the file.
    shirt = schwag_pb.Shirt(buff)

    self.text = shirt.text()
    if shirt.has_project():  # Use project name if present.
      self.author = shirt.project()
    else:
      self.author = 'google shirt'

  def WriteShirt(self, filename):
    """Writes a shirt protocol buffer object out with the quote data."""
    shirt = schwag_pb.Shirt()      # Create empty protocol buffer object.
    shirt.set_text(self.text)      # Set fields in it.
    shirt.set_project(self.author)

    # Here shirt.Encode() creates the raw bytes for this protocol buffer.
    pywrapfile.File.WriteStringToFileOrDie(shirt.Encode(), filename)
