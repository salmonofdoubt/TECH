#!/usr/bin/env python
# encoding: utf-8
"""
functions
"""
import sys


def break_words(stuff):
	words = stuff.split(' ')
	return words
	
def sort_words(words):
	return sorted(words)
	
def print_first(words):
	word = words.pop(0)
	print "First word: %s." %word
	
def print_last(words):
	word = words.pop(-1)
	print "Last word: %s." %word
	
def sort_sentence(sentence):
	words = break_words(sentence)
	return sort_words(words)

def print_first_and_last(sentence):
	words = break_words(sentence)
	print_first(words)
	print_last(words)

def print_first_and_last_sorted(sentence):
	words = sort_sentence(sentence)
	print_first(words)
	print_last(words)
	
def main():
	sentence = raw_input('Your sentence > ')
	print sentence
	
	print break_words(sentence)
	print sort_words(sentence)
	
	print sort_sentence(sentence)
	
	print_first_and_last(sentence)
	
	print_first_and_last_sorted(sentence)
	
	
	
if __name__ == '__main__':
	main()


