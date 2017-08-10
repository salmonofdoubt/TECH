regex
---------------

1. Escape chars meaning:
\ number
matches contents of the group with that number

\A
matches only at the start of a string

\b
matches empty string at the beginning or end of a word

\B
matches empty string in the middle of a word

\d
matches any digit (0-9)

\D
matches any character that is not a digit

\s
matches any white space character

\S
matches any character that is not white space

\w
matches any alphanumeric character

\W
matches any character that is not alphanumeric

\Z
matches only at the end of a string


2. special char meaning

.
---
'p.thon' matches python,p!thon, p2thon, but not pyython

[ ]
---
'T[iy]ger' matches Tiger or Tyger (but not Tiyger)
often used [A-Z] or [a-z]

⁁
---
'[⁁a]' matches any character that isn't ‘a’.

$
---
't$' matches 'bright' but
not 'tender'

re1 | re2
---
'python' | 'asp' first looks in a string for 'python'. If not found, it then
looks for 'asp'

{ number }
---
'y{3}' matches 'pyyython' but not 'python'

()
---
r 'Phone: (\d{3})-(\d{3}-\d{4})' looks for a phone number, with the area code in group 1 and the number in group 2.

\
---
'\$' searches for the $ character in text instead of treating $ as an "end of line or string" code.


3. repeats by using +, *, ?, or {}

*
---
matches the previous character any number of times, including none.
py*thon matches pthon, python, pyython, and so on.

+ 
---
matches the previous character one or more times.
py+thon matches python and pyython, but not pthon.

?
---
matches the previous character zero or one times.
py?thon matches pthon and python, but not pyython.

{}
---
py{5}thon matches an exact number of repeats: pyyyyython
· py{1,3}thon matches a range of repeats: python, pyython, and pyyython.




import re
dir(re) -- findall


zipcode = r'Zippo:\s*\d\d\d\d\d' # any number of whitespaces followed by 5 numbers
addr = "bla Zippo:  32433"
re.findall(zipcode, addr)
['Zippo:   32433']

