#!/usr/bin/python2.4 -tt

list = ['aba', 'cab', 'bbc']

def Func1(s):
  return s[0]

def Func2(s):
    return s[1]

def Func3(s):
    return s[2]

print sorted(list, key=Func1)
print sorted(list, key=Func2)
print sorted(list, key=Func3)



# This is the standard boilerplate that calls the main() function.
#if __name__ == '__main__':
#  main()
