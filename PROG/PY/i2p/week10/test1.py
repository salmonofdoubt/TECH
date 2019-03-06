import urllib
import re

def UrlToText(url):
  file = urllib.urlopen(url)
  contents = file.read()
  return contents

user_momapage = 'https://orginfo.corp.google.com/koyanagi?format=xml'
user_string = UrlToText(user_momapage)

match = re.search(r'<location>(\w\w(\-)\w\w\w)|</location>',user_string)
user_office = match.group(1)  

print user_office
