#!/usr/bin/python2.4
#
# Copyright 2008 Google Inc. All Rights Reserved.

"""Unittest Lab exercise.

Implement a "Synonym Dictionary", ie, a data structure that holds
and can return synonym information about words.

This implementation contains at least one bug that should be found
in unittesting.
"""

__author__ = """nnorwitz@google.com (Neal Norwitz),
								nlesiecki@google.com (Nicholas Lesiecki)"""


def _GetSynonymsFromFile(synonym_file):
	"""Return a list of lists which contain the synonym information.

	Each element will contain a list with at least 1 word (strings).	The first
	word is the target word, the remaining word(s), if any, are the first word's
	synonyms.

	Args:
		synonym_file: the data file which contains the synonym dictionary. This
				function will close the file once it has finished reading from it.

	Returns:
		a list of lists of words. The outer list contains one list per target word
		in the data file

	Raises:
		IOError: an underlying file operation failed
	"""
	result = []

	try:
		for line in synonym_file:
			# Break words into a list and ignore empty lines, lines with only
			# whitespace, and empty strings.	Ignore words that
			# appear on a line by themselves, thus having no synonyms.
			# Possible feature enhancement: discard all lines starting with '#'
			words = [w for w in line.split() if w]
			if len(words) > 1:
				result.append(words)
	finally:
		synonym_file.close()
	return result


class NoValuesError(Exception):
	"""There were no synonyms in the dictionary file."""


class SynonymDict(object):
	"""Simple collection of synonyms."""

	def __init__(self):
		self._filename = None
		self._synonyms = None

	def IsInitialized(self):
		"""Determine if the dictionary is in a usable state.
		
		Returns:
			true: if data was successfully loaded using LoadDictionary()
			false: if data was not successfully loaded
		"""
		return bool(self._synonyms)

	def LoadDictionary(self, filename):
		"""Load a dictionary from filename.

		Args:
			filename: path to the data file which contains the synonym dictionary

		Raises:
			NoValuesError: there are no synonyms in the file
			IOError: an underlying file operation failed
		"""
		
		
		# Exception safety rule #1:	 Perform any operations which may potentially
		# fail *before* changing the state of the object.
		synonyms = {}

		the_file = file(filename, 'rU')
		all_words = _GetSynonymsFromFile(the_file)
		for word_list in all_words:
			word = word_list[0]
			# for this word, add all the other words as synonyms
			word_synonyms = word_list[1:]
			word_synonyms.sort()
			synonyms[word] = word_synonyms

		if not synonyms:
			raise NoValuesError('No synonyms were read from file: "%s"' % filename)

		# Exception safety rule #2:	 Once all operations which might fail have
		# successfully completed, go ahead and update the state of the object.
		self._filename = filename
		self._synonyms = synonyms

	def GetSynonyms(self, word):
		"""Return the synonyms for a word.

		Args:
			word: the target word for which we want synonyms

		Returns:
			The list of known synonyms for word
		"""
		return self._synonyms.get(word, [])