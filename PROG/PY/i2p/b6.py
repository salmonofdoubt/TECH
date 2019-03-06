#!/usr/bin/env python
# encoding: utf-8
"""
STD BOILERPLATE
Created by André Baumann on 2011-08-23.
Copyright (c) Google Inc. 2011. All rights reserved.
"""
import sys
import os


class BankAccount(object):
    def __init__(self, initial_balance=0):
        self.balance = initial_balance

    def deposit(self, amount):
        self.balance += amount
    def withdraw(self, amount):
        self.balance -= amount
    def overdrawn(self):
        return self.balance < 0


my_account = BankAccount(15)
my_account.withdraw(5)
print my_account.balance


