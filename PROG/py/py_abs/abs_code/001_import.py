'''
http://en.wikibooks.org/wiki/Non-Programmer%27s_Tutorial_for_Python_3.0
http://docs.python.org/release/3.0.1/tutorial/index.html
'''

import sys
print('1. version')
print(sys.version_info)
input()
print('I am a fatal error:', file=sys.stderr)
input()
print('3. There are <', 2**32, '> possibilities!', sep="")
input()
print(sys.path)
print('4. append to path: sys.path.append(\'/my/new/path\'')
input()
sys.path.append('/my/new/path')
print(sys.path)

print('\nEnd')



