#!/usr/bin/env python
# encoding: utf-8

"""
py_template.py

Created by André Baumann on 2011-08-23.
Copyright (c) 2011 __MyCompanyName__. All rights reserved.
"""

import sys
import os

class NameTag:
  def __init__(self, myname):
    self.myname = myname

  def main():
    pass


if __name__ == '__main__':
  main()



import sys
-----------------------
PYTHON TODO
- add to SREU: help(command)
- add to SREU: dir() -- modules loaded
- add to SREU: type
+ strings2
+ list2
- split, join
+ listtest.py
+ dictionaries
+ some code to test regex

-----------------------
Py4Dum
-----------------------

ickling data
---------------
import cPickle
#pickle and cPickle modules let you store data between runs of a program.

sqlite
---------------
installed with Python2.5
??

reduce"-- a function"
---------------
>>> mylist = [2, 4, 6, 8]
>>> reduce(lambda x, y: x*y, mylist)
384

>>> sum(range(20))
190

map"-- a function"
---------------
>>> mystring = "hello kitty"
>>> map(None, mystring)
['h', 'e', 'l', 'l', 'o', ' ', 'k', 'i', 't', 't', 'y']


lambda"-- a function"
---------------
>>> filter(lambda x: x%5 is 0, xrange(76))
[0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75]

>>> data = [10, 2, 7, 5]
>>> filter(lambda x: x>5, data)
[10, 7]


simple listcomp
---------------
mylist = [x.lower() for x in mylist]


mylist = ['ABC', 'fOO', 'bar']
tmp = []
for x in mylist:
tmp.append(x.lower())
mylist = tmp



iterator
-------------------------
An iterator is a Python object that produces elements one at a time

s = 'abc'
it = iter(s)
it
<iterator object at 0x00A1DB50>
it.next()
a
it.next()
b
it.next()
c
it.next()
Traceback (most recent call last):
File "<stdin>", line 1, in <module>
StopIteration


Generators
------------------
special kind of function that creates an iterator 
use yield statement to return data (in contrast to regular functions that use return statement





new classes - old classes
-------------------------

a new-style class always inherits from object, either directly 
class Myclass(object):

or indirectly by inheriting from one of Python's built-in types
class Myclass(dict):
  
which inherits from object.


old classes
class Myclass:
    


checking datatype
--------------------------
type(fido)
#<type 'instance'>
type(y)
#<type 'int'>
type (Lab)
#<type 'classobj'>
type(len)
#¯type 'builtin_function_or_method'>

---

class NameTag:                # super class
  
class GeekNameTag(NameTag):   # a subclass, calling  superclass

---

list -> mutable
import copy
copy.deepcopy()

dict -> mutable but keys(hashes) are not


sortkey=sorted(mydict)

mydict.keys()
mydict.values()

mydict['newdictkey']='newdictvalue'

mydict.popitem()
mydict.pop()

make shallow copy
dictcopy = dict.copy()


string-> immutable
tuple -> immutable


-----------------------
DAY2 reverse order
-----------------------

WRITE STUFF IN PYTHON!!! EVERY DAY!!! YAY!!!

go/python101
go/python201


---Resuse---
reuse, or check existing modules:
import babynames
help(babynames)
help(babynames.ExtractNames)

- with '''description''' right under the method, help will then display it.
Note: normally, ''' ''' is just a string over multiple lines. Directly under a method it has no impact.
Also backslash continues long lines..


import shutil
import os 

#!/usr/bin/python2.4$

def main():
  for name in sys.argv[1:]:
    dirlist = os.listdir(name)
    for filename in ...:
      if not 
        print os.path. 
      
      name + filename
if __name__ == "__main__":
  main()
  
  
sys module

 15 set sw=2$
 16 set ts=2$
 17 set et$
 18 set list $
 19 set number$



---regex---
match
findall
help(re)

pattern = raw_input('regex pattern: ' )
text = raw_input('text to match: ')

def PrintMatch(pattern, text):
	m = re.match(pattern, text)
	if m is None:
		print: no match
	else:
		print m.groups()
		
pattern = raw_input('regex pattern: ' )
text = raw_input('text to match: ')

PrintMatch(Pattern, Yourtext)


\d\d digits
\w\w words


r'1\d\d$|2[0-4]\d25[0-5]|\d|\d$\d|\d$
() -- group



>>> print '\n'


>>> print '\\n'
\n
>>> print r'\\n'
\\n
>>> print r'\n'
\n




-------------------------
DAY1 reverse order
-------------------------

---Dictionary---
keys:values

y = {}
y['a'] = 'alpha'
y['b'] = 'beta'
y['g'] = 'gamma'
print y
{'a': 'alpha', 'b': 'beta', 'g': 'gamma'}

print y['a']
alpha
y['a'] = 6
print y
{'a': 6, 'b': 'beta', 'g': 'gamma'}

for x in y: print x						#use x or anything, always prints the key
... 
a
b
g

for x in y.values(): print x	
... 
6
beta
gamma



y = {}
y[0] = 1
y[1000] = 1
y[10000] = 1
y
{0: 1, 1000: 1, 10000: 1}





---Tulples---
tuples are inmutable lists
tup = (1,2,'hi')
print len(tup)
3
print tup[2]
hi

tup[2] = 'bye'
...'tuple' object does not support item assignment

*but*
tup = ('hi')
tup
'hi'

(x,y,z)=(23,45,'hint')
x
23
y
45
z
'hint'






---List---

line = '32 4$ tomato'
line.split(',')
['32', ' 4$', ' tomato']
a = line.split(",")
separator = ":" 
separator.join(a)
'32: 4$: tomato'
---------------------------------
sorted() makes *new* list,
.sort() *modifies* existing list:
---------------------------------
a = [5,2,1,7]
print sorted(a)
[1, 2, 5, 7]
print a
[5, 2, 1, 7]

a.sort()
print a
[1, 2, 5, 7]

strss = ['klfr','drewscd','ssef','qefhbfgh']
print sorted(strss[1])
['c', 'd', 'd', 'e', 'r', 's', 'w']

sorted(a, key=len)
['d', 'bb', 'aaa', 'cccccc']

a = ['aaa', 'bb', 'cccccc', 'd']
sorted(a)
['aaa', 'bb', 'cccccc', 'd']

--- %Operator ---
'I ate %d donuts at %d am' % (4,10)
'I ate 4 donuts at 10 am'


if a != '': print 'non-empty'
... 
non-empty

if a:
...  print 'True'
... 
True

---Find---
a
'asdf'
a.find('x')
-1



---Slice---
a
'Andre'
print s[:-3]
An
print s[-3:]
dre 


---Import---
import sys
sys.something 

---Data types--- 
str(200)

help(str)

---Inpreter---
#!/usr/bin/python2.4 -tt
>>


---Main---
executes the main function instead if there is no module:
<<
# This is the standard boilerplate that calls the main() function.
if __name__ == '__main__':
  main()
>>

===============================================================







---



There are two types of rules:

Rules are processed from the top to the bottom. Therefore:

Put general rules before specific rules.
Put additive rules before subtractive rules.

setup
excercise


g4 filelog -m10 shut-up-abaumann.html
g4 client -a //depot/sandbox/g4codelab/...

22705222
    	OCL=22705213


BIND9 on grail (172.28.9.27)

dhcp-172-28-9-201:~ abaumann$ ping -t 1 grail
PING grail.dub.corp.google.com (172.28.9.27): 56 data bytes
64 bytes from 172.28.9.27: icmp_seq=0 ttl=64 time=0.166 ms

abaumann@grail:~$ sudo /etc/init.d/bind9 restart
 * Stopping domain name service... bind9
   ...done.
 * Starting domain name service... bind9
   ...done.

dhcp-172-28-9-201:~ abaumann$ dig +short @grail rte.ie
89.207.56.140

from Mac:
ssh grail top -b | grep -i bind

grail:
top -p 1795

top - 16:32:05 up 2 days,  2:38,  7 users,  load average: 0.51, 0.62, 0.63
Tasks:   1 total,   0 running,   1 sleeping,   0 stopped,   0 zombie
Cpu(s):  8.4%us,  1.4%sy,  0.0%ni, 90.1%id,  0.0%wa,  0.0%hi,  0.1%si,  0.0%st
Mem:   8129048k total,  7779604k used,   349444k free,   229692k buffers
Swap: 23814136k total,       44k used, 23814092k free,  1959340k cached

  PID USER      PR  NI  VIRT  RES  SHR S %CPU %MEM    TIME+  COMMAND                   
 1795 bind      20   0  217m  29m 2256 S    3  0.4   0:06.49 named       

Starting...

+ ------ + ------- + ------------------ + ------------ +
| Second | Queries | Avg. response (ms) | Success rate |
+ ------ + ------- + ------------------ + ------------ +
| Â Â Â Â Â 0 | Â Â Â Â 100 | Â Â Â Â Â Â Â Â Â Â Â Â Â 19.60 | Â Â Â Â Â Â Â Â 0.78 |
| Â Â Â Â Â 1 | Â Â Â Â 200 | Â Â Â Â Â Â Â Â Â Â Â Â Â Â 2.83 | Â Â Â Â Â Â Â Â 0.76 |
| Â Â Â Â Â 2 | Â Â Â Â 300 | Â Â Â Â Â Â Â Â Â Â Â Â Â Â 3.25 | Â Â Â Â Â Â Â Â 0.76 |
| Â Â Â Â Â 3 | Â Â Â Â 400 | Â Â Â Â Â Â Â Â Â Â Â Â Â Â 7.33 | Â Â Â Â Â Â Â Â 0.76 |
| Â Â Â Â Â 4 | Â Â Â Â 500 | Â Â Â Â Â Â Â Â Â Â Â Â Â Â 9.71 | Â Â Â Â Â Â Â Â 0.73 |
| Â Â Â Â Â 5 | Â Â Â Â 600 | Â Â Â Â Â Â Â Â Â Â Â Â Â 61.15 | Â Â Â Â Â Â Â Â 0.75 |
| Â Â Â Â Â 6 | Â Â Â Â 700 | Â Â Â Â Â Â Â Â Â Â Â Â Â 27.04 | Â Â Â Â Â Â Â Â 0.74 |
| Â Â Â Â Â 7 | Â Â Â Â 800 | Â Â Â Â Â Â Â Â Â Â Â Â Â 25.97 | Â Â Â Â Â Â Â Â 0.74 |
| Â Â Â Â Â 8 | Â Â Â Â 900 | Â Â Â Â Â Â Â Â Â Â Â Â Â 28.97 | Â Â Â Â Â Â Â Â 0.74 |
| Â Â Â Â Â 9 | Â Â Â 1000 | Â Â Â Â Â Â Â Â Â Â Â Â Â 22.76 | Â Â Â Â Â Â Â Â 0.75 |
+ ------ + ------- + ------------------ + ------------ +


sudo tcpdump -i eth0 port 53 -w /tmp/p53_1.cap -s 0
sudo tcpdump -qns 0 -A -r /tmp/packets.cap



studio one music software mac



sudo tcpdump -i eth0 port 53 -w /tmp/p53_1.cap -s 0 

scp p53_1.cap.zip abaumann@172.26.139.128:/home/abaumann/Desktop/p53_1.cap.zip


abaumann@grail:~$ stubby web 12345

172.28.9.27

http://s/?fileprint=//depot/google3/borg/util/borgusage_collectorlib.py&hilite_regexp=pywrapexpvar&line=28#18



list active interfaces

ping -I fromIP targetIP /sbin/ifconfig -a netstat -rn

generate some traffic
wget -S http://www.spiegel.de 
telnet mx1.spiegel.de 25 Ctrl+C
- check file in wireshark OR grail: ethereal output.cap (starts ethereal)

Mac sudo chown abaumann /dev/bpf* run Wireshark app, filter string: smtp

more from GSA times
tcpdump -i any -s 65535 -w /tmp/file.cap
tcpdump -I eth0 -w /tmp/dump.txt port 80 host 
tcpdump -s 0 -x -w output.txt port 80
tcpdump -s 0 -x -w output.cap

nmap nmap -sT -p 4000-4007 216.239.43.1-12

sudo tcpdump -i eth0 -c count -w /tmp/packets.cap
sudo tcpdump -i eth0 port 53 -w /tmp/packets.cap -s 0
view:
sudo tcpdump -qns 0 -A -r /tmp/packets.cap


abaumann@grail:~$ telnet www.google.com 80
Trying 2a00:1450:400b:c00::63...
Connected to www.l.google.com.
Escape character is '^]'.
GET /__rPc_sWiTcH__ HTTP/1.0

measure server instead	
Borg with test configs, naming servers, 	
pyDNS framework	

load
perforce, load config 
write data into Borgmon template
traffic mon


external Honest DNS (auth, but mainly recursive)
privacy > traffic per user
	get approval from team
	external 
	
GTC (authoritative)
	ns1..4
	depending on origin > move to another answer

pDNS (authoritative, some recursion, BIND)
	in cluster (10.x.x.x)
	

tm/yw

borg jobs
picolo
rpcL

grail: 

/home/build/google3/





https://wiki.corp.google.com/twiki/bin/view/Codelab/PerforceExerciseUnix


3

{- tbd / + done}
<snippets before July under (eso)>

SREU
---------
- Intro to bigtable
+ Install Bind9 server
- Intro to Stubby

- early project John and Ryan / Eng
- research DNS Load Balance framework
- create visual

P4 client still working?
---------
+ Syncing default CL @22619432
+ Syncing default CL @22620207
Change 22620789 renamed change 22620798 and submitted.

setup:
https://wiki.corp.google.com/twiki/bin/view/Codelab/PerforceForUnix

excercise:
https://wiki.corp.google.com/twiki/bin/view/Codelab/PerforceExerciseUnix

Postini
------------
- drain remaining tickets
- start looking into OSO cases
- Auth Bug 

Misc
------------
- Installed BlueTooth OTP (it's a charme')
