#!/usr/bin/env python
# encoding: utf-8
"""
summary thus far
"""
import sys

print "---Practice all---"
print "You\'d need to know \'bout escapes with \\ that do \n newlines \n and \t tabs."

poem = """
\tThe lovely world
with logic so firmly planted
cannot discern \n the needs of love
nor comprehend passion from intuition
and requires an explanation
\n\t\twhere there is none. 
"""
print "-----------------"
print poem
print "-----------------"

five = 10 - 2 + 3 - 6 
print "five: %s " %five

def secret_formula(started):
	beans  = started * 500
	jars   = beans / 1000
	crates = jars / 100
	return beans, jars, crates		# awesome python returns multiple values

def main():
	start_point = 10000
	beans, jars, crates = secret_formula(start_point)

	print "Start point: %d" %start_point
	print "Have %d beans, %d jars, %d crates." %(beans, jars, crates)

	start_point = start_point / 10
	print "We can also do it this way:"
	print "Have %d beans, %d jars, %d crates." %secret_formula(start_point)

if __name__ == '__main__':
	main()


