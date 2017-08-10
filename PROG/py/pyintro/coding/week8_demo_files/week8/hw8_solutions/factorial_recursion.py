#!/usr/bin/python2.6

def Factorial(n):
  if n == 1:
    return n
  else:
    return n * Factorial(n - 1)

def main():
  num = raw_input('Find the factorial for: ')
  print Factorial(int(num))

if __name__ == '__main__':
  main()
