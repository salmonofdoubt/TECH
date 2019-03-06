#!/usr/bin/env python
# 12_Modules

import calendar
year = int(input('Type in the bloody year: '))
calendar.setfirstweekday(calendar.SUNDAY)
calendar.prcal(year)   # Prints the calendar for an entire year as returned by calendar().         


from time import time, ctime
 
prev_time = ""
while True:
    the_time = ctime(time())
    if prev_time != the_time:
        print("The time is:", ctime(time()))
        prev_time = the_time
