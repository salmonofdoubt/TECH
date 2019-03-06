PYTHON

- CPython
- Jython  Java
- CPy is primary SRE language
- C only for kernel or SQL hacking
- Py as long as not performance critical
- Py good use of namespaces

- help()
- dir()
- __builtins__
- set_trace()

- python -c -- run one-liner
- pickle -- saves program state

copy vs deepcopy
sort vs sorted
- reverse vs reversed
- refactoring
- /bbrazil/sreu/grep/grep.py

- python and djungle for websites, api
- del d['a'] -- delete element
- r'\n'-- raw \n, not a new line :)
- u'text' -- unicode
(,) OR , -- both empty tuple

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


Dicts {keys:values}
y = {}
y['a'] = 'alpha'
y['b'] = 'beta'
y['g'] = 'gamma'
print y
{'a': 'alpha', 'b': 'beta', 'g': 'gamma'}

for x in y:
	print x					#x == anything
>>
a
b
g

for x in y.values(): 
	print x	
>>
6
beta
gamma

- Tulples -- inmutable lists
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

- Lists 
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

a = 'asdf'
a.find('x')
-1

a = 'Andre'		Slicing
print s[:-3]
An
print s[-3:]
dre 

Set 
is mutable

- Import
import sys
from sys import argv
sys.something 

- Data types 
str(200)
help(str)

Interpreter
#!/usr/bin/python2.4 -tt
- sys.stdout

- Generators / Iterator
yield, rather than return

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

- Garbage collection
gc.xxx()

- Itertools
everything iterable
for path in paths
/
u
s
r
/			:|

- transpose a matrix
zip(F matrix)
  
- continue
for i in range(...)
	if n% i == 0:
		return False
	else:
		return True
- lambda x: x		--just an adhoc fct 

- has key:
	d = {..}
	x in d	--	same as d[x]

- min, max, sum 


- Exceptions
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

	
- MapReduce 

1. Mapping: process logical records of input data and produce intermediate key/value pairs
Shuffle: copy intermediate data destined for a single output shard to a single location for reducing.

e.g.	1 file, split by line, give to workers 
														worker1: (key(mylines):value())
worker2: (key(mylines):value())	

Shuffle: copy intermediate data destined for a single output shard to a single location for reducing.
		
Reduce
merges all the values for the same intermediate key to produce output 		
	key/value pairs 
		line1 went to worker1	> result is:	<x>
		line2 went to worker2 	> 			<y>
		line3 went to worker1 (!) > 			<z>



Stubby
(to pass args remotely) easy RPC mechanism,
create object based on pywraphttpserver.HTTPServer
pywrapnetutil

- HTTP server (to monitor a service (executable))
every job has a HTTP server
statusz, varz, rpcz, threadz, heapz, profz
basically it shows jobstatus 

eg another program can parse heapz to visualize
--- RecordIO Files
RecordIO is a library to handle files containing variable-sized records
Most commonly used to write protobufs to disk

- Protocol Buffers
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

