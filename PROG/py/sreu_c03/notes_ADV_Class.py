INTERMEDIATE PY (BRAIN)

- python and djungle for websites, api

http://linuxgazette.net/107/pai.html
http://docs.python.org/library/threading.html
http://en.wikipedia.org/wiki/Producer-consumer_problem
http://docs.python.org/library/exceptions.html

DAY4 
-------------------------

del d['a'] -- delete element
r'\n'-- raw \n, not a new line :)
u'text' -- unicode
(,) OR , -- both empty tuple
set (is mutable)

Thruth: 1, True, 

continue

for i in range(...)
	if n% i == 0:
		return False
	else:
		return True

lambda x: x		--just an adhoc fct 

has key:
d = {..}
x in d	--	same as d[x]

min, max
sum 

sort vs sorted
reverse vs reversed

help()
dir()
__builtins__
set_trace()

python -c -- run one-liner

pickle -- saves program state

copy vs deepcopy

refactoring

- /bbrazil/sreu/grep/grep.py


DAY3 PYGLIB
-------------------------

--- MapReduce
2 methods: 
Map: process logical records of input data and produce intermediate key/value pairs

Shuffle: copy intermediate data destined for a single output shard to a single location for reducing

	Map:
	process logical records of input data and produce intermediate key/value pairs
	e.g.	1 file, split by line, give to workers 
														worker1: (key(mylines):value())
														worker2: (key(mylines):value())
	
	Shuffle
	Shuffle: copy intermediate data destined for a single output shard to a single 
	location for reducing
		
	Reduce
	Reduce: merges all the values for the same intermediate key to produce output 		
	key/value pairs 
		line1 went to worker1	> result is: <x>
		line2 went to worker2 > 					 <y>
		line3 went to worker1 (!) > 			 <z>



--- Stubby (to pass args remotely)
  easy RPC mechanism

create object based on pywraphttpserver.HTTPServer
pywrapnetutil


--- HTTP server (to monitor a service (executable))
every job has a HTTP server
statusz, varz, rpcz, threadz, heapz, profz
basically it shows jobstatus 

eg another program can parse heapz to visualize
--- RecordIO Files
RecordIO is a library to handle files containing variable-sized records
Most commonly used to write protobufs to disk

--- Protocol Buffers
	data format, written to disk
	used by stubby RPC system
http://www.corp.google.com/eng/howto/infrastructure/protocol-buffer.html


exercise: thread pool 
http://sourcerer/?fileprint=//depot/google3/pyglib/thread_pool/thread_pool.py

https://cs.corp.google.com/#google3/pyglib/thread_pool/thread_pool.py&sq=package:google3%20-file:experimental&q=thread_pool.py&type=cs

from google3.pyglib.thread_pool import thread_pool

--- Usage at google3

- logging
from google3.pyglib import logging

- gfile
from google3.pyglib import gfile
f = gfile.GFile(pathtofile, 'r')


- build file:
...
blaze: links / binds all C++ libs to the target file you wrote

py_binary(name = "zz",
          srcs = [ "zz.py" ],
          deps = [ "//pyglib"]
)

Build with:
$ blaze build xx/yy:zz
Run with:
$ ./blaze-bin/xx/yy/zz --arg1 --arg2

Changes in the Python code don't require a new blaze build
Changes in the BUILD file require a new blaze build



./urfile.py --helpshort


- par files (py archives)
blaze build ../../..par
 


-------
#!/usr/bin/env python
# encoding: utf-8
'''
- std boilerplate - 
Created by ___André Baumann___ 2011
Copyright (c) Google Inc. 2011. All rights reserved.
'''
import sys
import os

from google3.pyglib import app
from google3.pyglib import flags

FLAGS....(underlying C++ stuff)

FLAGS = flags.flag

def main(unused_argv):
	print 'Hello there', FLAGS.name
	if.FLAG....

  #sys.exit(0) 

if __name__ == '__main__':
	app.run()
-------



DAY2
-------------------------
Isaac
/home/isaacc/downloader


- Threading
http://docs.python.org/library/threading.html




- Exceptions
http://docs.python.org/library/exceptions.html


s = raw_input('')
try:
	call fct(s)
except ValueError:
	print 'you are screwed'
else:
	print 'input was...'
finally:
	print 'executing finally clause which is independent from success or 	
																														failure...'
- Raise Exceptions
if  ...:
	raise ValueError(...)
	
class InputError(Exception):

class MapError(Exception):


- OOP

class Foo(object):
	def __init__(self):
		self._a  =				use in this class but also external classes 
		self.__a = 				use only in this class


data abstraction:
	obj are abstractions, holding data
	classes, inherit from object, which is the in-built superclass

encapsulation
	access to data through defined interfaces
		
		
modularity

polymorhism
	diff data types tb handled using uniform interface
	like str(), can receivce any obj
	
inheritance
	ypur class will inherit from (object), 

cmd: dir(object)
cmd: a.__class__

duck typing
	
functions as objects

decorators
	@staticmethod
	def Size(filename)
	file.size('/etc/passwd')
	
A Python decorator is a specific change to the Python syntax that allows us to ‘	more conveniently alter functions and methods (and possibly classes in a future version). This supports more readable applications of the DecoratorPattern but also other uses as well.’

classes are just objects

	class Adder(objects):
	...
	c = Adder
	

	
- std lib
re
copy 
	copy.deepcopy(c)
os
date
time
	sleep
threading
subprocess
popen2
signal	
sockets

- std lib II
email
json

md5
sha

wave
imghdr	fileformat
sndhdr

urllib
ftplib
smtplib
simpleHTTPserver

htmllib
xml

sys
	argc, no argv, use len(argc)
	
	


DAY1
-------------------------
- Design Review


CPython
Jython  Java

sys.stdout
---

Generators / Iterator
yield (uses local execution frame), rather than return


(ord(x) for x in "Hello")
<generator object at 0x30f120>
>>> list(_)   #list last entry
[72, 101, 108, 108, 111]

>>> def Gen(x):
...   while True:
...     yield x
...     x += 1

>>> for x in Gen(10):
...   if x > 15: break
...   print(x)
... 
10
11
12
13
14
15
>>> 


---

garbage collection
gc.xxx()

---
itertools

everything iterable
for path in paths
/
u
s
r
/			:|

---
transpose a matrix
zip(F matrix)

---

dicts: 
d.setdefault('baz')
factory funct

---
correct print formating

---

def f(a=[]):	 --don't, if mutable, next call might reset the whole structure
 a.append(1)

rather:
def f(a=None):
	now if a list is passed, detects None, and uses list

---

def Func(a, b=2, *c, **d)	
b is the default
* rest of args is a list 
** rest of args is dict						

names tuples
a = (1,2,3)
a.x


--- PreChat
- Py is primary SRE language
- C only for kernel or SQL hacking
- if you read C, other language readability 
- Py: good use of namespaces
- as long as not performance critical


- maintenance
- design process

- long term support

fontcreek
- source control
  info on updates (versions)
  wiki documentation
  someting is dead, but new stuff does not yet work

- borgmon deprecated (organically)
 BCL borg config files
 var.instance.shard.job {}  -- 16 permutations

- colossus Flex: charged for whats being used
- From machine requests to quotas
	PMs: trading ressources
	hoarding
	over-subscription
  