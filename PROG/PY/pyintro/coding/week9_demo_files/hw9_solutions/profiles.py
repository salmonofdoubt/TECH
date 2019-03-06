#!/usr/bin/python2.6

import csv
import re
import urllib

def UrlToText(url):
  return urllib.urlopen(url).read()

def main():
  fieldnames = ['ldap', 'fullname', 'title', 'managerldap', 'department']
  ldaps = open('ldaps.txt', 'r').read().replace('\n', '').split(',')
  writer = csv.DictWriter(open('results.csv', 'w'), fieldnames)
  header_row = {}

  for fieldname in fieldnames:
    header_row[fieldname] = fieldname

  rows = [header_row]

  attr_map = [(r'<displayname>(.+)</displayname>', 'fullname'),
              (r'<title>(.+?)</title>', 'title'),
              (r'<manager>(\w+)</manager>', 'managerldap'),
              (r'<department>(.+)</department>', 'department')]

  for ldap in ldaps:
    who_url = 'https://orginfo.corp.google.com/'
    who_url += ldap + '?format=xml'
    who_text = UrlToText(who_url)
    row = {'ldap': ldap}

    for attr in attr_map:
      row[attr[1]] = re.search(attr[0], who_text).group(1)

    rows.append(row)

  writer.writerows(rows)

  print 'done.'

if __name__ == '__main__':
  main()
