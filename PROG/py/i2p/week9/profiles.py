#! /usr/bin/python

import re
import urllib
import csv

def UrlToText(url):
  url_file = urllib.urlopen(url)
  contents = url_file.read()
  return contents

def main():
  ldaps_file = open('ldaps.txt','rU').read()
  
  list1 = ldaps_file.split(',')
  list2 = []
  for x in list1:
    y =  x.strip()
    list2.append(y)
   
  d = {}
  list3 = []
   
  for ldap in list2:

    
    moma_page = 'https://orginfo.corp.google.com/%s?format=xml' %(ldap)
    employee_str = UrlToText(moma_page)
    
    managerldap = re.search(r'<manager>(.*?)</manager>',employee_str)
    d['managerldap'] = ''.join(managerldap.group(1))
    
    department = re.search(r'<department>(.*?)</department>',employee_str)
    d['department'] = ''.join(department.group(1))
    
    
    fullname = re.search(r'<displayname>(.*?)</displayname>',employee_str)
    d['fullname'] = ''.join(fullname.group(1))
    
    ldap = re.search(r'<email>(.*?)</email>',employee_str)
    d['ldap'] = ''.join(ldap.group(1))
    
    title = re.search(r'<title>(.*?)</title>',employee_str)
    d['title'] = ''.join(title.group(1))
    
    list3.append(d)
    d = {}
    
  results = open('results.csv','w')
  col_names = ['ldap','fullname','title','managerldap','department']
  
  results_writer = csv.DictWriter(results,col_names)
  
  header_row = {'ldap':'ldap',
                'fullname':'fullname',
                'title':'title',
                'managerldap':'managerldap',
                'department':'department'}
  
  results_writer.writerow(header_row)
     
  results_writer.writerows(list3)
  
  
  
  
    
if __name__ == '__main__':
  main()
