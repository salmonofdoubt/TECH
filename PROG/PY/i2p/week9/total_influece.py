#! /usr/bin/python

import re
import urllib


def UrlToText(url):
  url_file = urllib.urlopen(url)
  contents = url_file.read()
  return contents

manager = raw_input("enter manager's ldap: ")

moma_page = 'https://orginfo.corp.google.com/%s?format=xml' %(manager)
employee_str = UrlToText(moma_page)

reportees_finder = re.findall(r'<reportees>',employee_str) 

while reportees_finder[0] == '<reportees>':
  reportees = re.findall(r'<email>(.*?)</email>',employee_str)
  reportees.remove(manager)
  
  for x in reportees:
    moma_page_reportees = 'https://orginfo.corp.google.com/%s?format=xml' %reportees
    

print reportees



