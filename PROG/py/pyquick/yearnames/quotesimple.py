#!/usr/bin/python2.4
# Copyright 2008 Google Inc. All Rights Reserved.

"""
Simple example of  a class.
quotesimple.py
nparlante@google.com

-An intance of a class is like a little hash table, containing .text,
.author, etc.

-'self' refers to the object itself. Setting self.foo effectively creates
a foo instance variable in the object

-__init__ is the constructor

-Clients create objects like this: quotesimple.Quote(arg, arg)

-'self' is an explicit first argument to everything -- easy to forget

-Use 'self' explicitly to call methods like self.Foo() or access ivars
like self.text -- also very easy to forget
"""

class Quote(object):  # This specifies 'object' as the superclass
  """The Quote class encapsulates a quote text and author."""

  def __init__(self, text, author):
    self.text = text
    self.author = author
    self.funny = False  # setting an ivar causes it to exist

    # naming an ivar starting with '_' is a hint to clients that they
    # should not access it directly. Starting with '__', more so.
    self._ssn = 0

  # Could have java-style Getters/Setters as below.
  # Could just let the client code access vars like quote.text directly.
  # Both those techniques are used in python, depending on the situation.

  def GetText(self):
    return self.text

  def SetText(self, text):
    self.text = text

  # This is a more interesting method example, doing
  # a real computation with the self state.
  def GetFormatted(self):
    """Returns a formatted text form of the quote, like:
    Nobody goes there anymore; it's too crowded.
    --Yogi Berra
    """
    return '%s\n--%s\n' % (self.text,  self.author)

# Here main() is in the class file. More typically, the class is defined
# in one file and main() is in a separate file.

def main():
  q1 = Quote("Nobody goes there anymore; it's too crowded.", "Yogi Berra")
  q2 = Quote("Wherever you go, there you are.", "Buckaroo Bonzai")

  print q1.GetText()
  print q2.GetFormatted()


if __name__ == "__main__":
  main()
