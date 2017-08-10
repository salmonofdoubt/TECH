#!/usr/bin/env python
# encoding: utf-8

def sum(numbers):
    total = 0
    for number in numbers:
        total += number
    return total
n = [1, 2, 5, 10, 13]
print sum(n)

