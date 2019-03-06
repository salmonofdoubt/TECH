#!/usr/bin/env python
#6 Prime number?
# range starts with 2 and only needs to go up the squareroot of n

n = input("Please enter a number greater than 1 (0 for exit):")
def isprime(n):
    for x in range(2, int(n**0.5)+1):
        if n % x == 0:
            return False
    return True
print (isprime(n))
