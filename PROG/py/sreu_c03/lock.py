#!/usr/bin/env python
# encoding: utf-8
"""
lock.py

Created by André Baumann on 2011-12-13.
Copyright (c) 2011 __MyCompanyName__. All rights reserved.
"""

import time
import thread

def myfunction(string,sleeptime,lock,*args):
    while 1:
	#entering critical section
        lock.acquire() 
        print string," Now Sleeping after Lock acquired for ",sleeptime
        time.sleep(sleeptime) 
        print string," Now releasing lock and then sleeping again"
        lock.release()
	#exiting critical section
        time.sleep(sleeptime) # why?

if __name__=="__main__":

    lock=thread.allocate_lock()
    thread.start_new_thread(myfunction,("Thread No:1",2,lock))
    thread.start_new_thread(myfunction,("Thread No:2",2,lock))

    while 1:pass


if __name__ == '__main__':
	main()

