#!/usr/bin/env python
# encoding: utf-8
"""
bashing2.py
Created by André Baumann on 2011-12-10.
Copyright (c) 2011 __MyCompanyName__. All rights reserved.
"""

import sys
import os

def main():
	
	while True:
		what = raw_input('part (finger):')
		how  = raw_input('tool (knife):')
		print '\"iscut return value\":', iscut(what, how)
		what = raw_input('again (y/n:)')
		if what == 'y':
			continue
		else:
			break
	
def iscut(part, tool):
	if (part == 'finger' and tool == 'knife'):
		return 'we cut our finger with a knife', 'X'
		
def exercise():
	

if __name__ == "__main__":
	sys.exit(main())
	
	
