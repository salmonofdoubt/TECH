#!/usr/bin/env python
#7_Adv'd Functions

print("Advanced Functions")
print("------------------")
print("\n1. recursive multiplication")
input()

def mult(a, b):
    if b == 0:
        return 0
    rest = mult(a, b - 1)
    value = a + rest
    return value
print("3 * 2 = ", mult(3, 2))

print("\n2. factorial")
input()

def factorial(n):
    if n <= 1:
        return 1
    return n * factorial(n - 1)
 
print("2! =", factorial(2))
print("4! =", factorial(4))
print("8! =", factorial(8))
print("16! =", factorial(16))


print("\n3. countdown")
input()

def count_down(n):
    print(n)
    if n > 0:
        return count_down(n-1)
 
count_down(15)

