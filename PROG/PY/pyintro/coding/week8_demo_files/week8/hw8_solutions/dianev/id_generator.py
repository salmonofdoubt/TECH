#!/usr/bin/python2.6

import random

def GenerateNumber(used_list):
  random_int = random.randint(100000, 999999)
  if str(random_int) in used_list:
    return GenerateNumber(used_list)
  else:
    append_str = ',' + str(random_int)
    updated_file = open('used_ids.txt', 'a')
    updated_file.write(append_str)
    return 'Your ID is ' + str(random_int) + '!'


def main():
  number_file = open('used_ids.txt', 'r')
  used_list = number_file.read().split(',')
  print GenerateNumber(used_list)

if __name__ == '__main__':
  main()
