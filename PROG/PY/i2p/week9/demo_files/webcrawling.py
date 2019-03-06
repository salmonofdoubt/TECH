import re
import urllib

def UrlToText(url):
  url_file = urllib.urlopen(url)
  contents = url_file.read()
  return contents
  
def main():
  my_moma_page = 'https://orginfo.corp.google.com/alberthwang?format=xml'
  employee_str  = UrlToText(my_moma_page)
  
  cc_match = re.search('<cost_center_number>(\d+)</cost_center_number>',employee_str)
  
  print cc_match.group(1)
  
  cc540_page = 'https://orginfo.corp.google.com/search/'
  cc540_page += 'cost_center_number:243?format=xml'
  cc540_str = UrlToText(cc540_page)

  ldaps = re.findall('<email>(\w+?)</email>',cc540_str)

  for ldap in ldaps:
    print ldap + ' is in Cost Center 174'
  for x,y in enumerate(ldaps):
    print x


if __name__ == '__main__':
  main()
