#!/usr/bin/env python
# encoding: utf-8
'''
- std boilerplate - 
Created by André Baumann 2011
Copyright (c) Google Inc. 2011. All rights reserved.
'''
import sys
import os

import datetime
def main():

	thirty_days = datetime.timedelta(days=30)
	my_date = datetime.date(2011, 2, 23)
	new_date = my_date + thirty_days

	print new_date.year # 2011
	print new_date.month # 3
	print new_date.day # 25
	print new_date.weekday() # 4

if __name__ == '__main__':
	main()
	