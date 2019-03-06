#! /usr/bin/env python 
# -*- coding: UTF8 -*- 
 
"""Simple CGI script 
 
"""  
import time 
 
now = time.strftime("%A %d %B %Y") 
 
def printcontent(): 
    print("Content-type: text/html") 
    print() 
 
def printheader(): 
    print("""<html> 
     <head> 
     <title>Simple CGI script</title> 
     </head> 
     <body>""") 
def printfooter(): 
    print("</body></html>") 
 
printcontent() 
printheader() 
print("""<h1>It's {0!s}!</h1> 
<p>Your server is correctly set up to run Python programs.</p>""".format(now)) 
printfooter() 
