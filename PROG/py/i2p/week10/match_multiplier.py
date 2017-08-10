import atom
import gdata.spreadsheet.service
import getpass
import sys
import re
import urllib

def UrlToText(url):
  file = urllib.open(url)
  contents = file.read()
  return contents

def getpassword():
  doc_client = gdata.spreadsheet.service.SpreadsheetsService()
  
  #invalid login (allow 3 tries to enter the password) #
  for num in range(3):
    try:
      doc_client.email = raw_input('ldap: ') + '@google.com'
      doc_client.password = getpass.getpass('password:') #rwscukvyywucornz
      doc_client.source = 'i2p gdata demo'
      doc_client.ProgrammaticLogin()
      break     
    except:
      if num == 2:
        sys.exit('Failed to give a valid password in 3 tries')
      else:
        print 'Incorrect username/password...try again.'
  return doc_client

def main():
  trix_client = getpassword()
  
  trix_key = '0AkYggUc972qFdHREQl9FcFNCaG9kWGxnckdYb0J5OEE'
  
  # get data from "data" sheet
  
  worksheet_feeds = trix_client.GetWorksheetsFeed(trix_key).entry
  
  sheet_id = worksheet_feeds[0].id.text.split('/')[-1]
  data_feed = trix_client.GetListFeed(trix_key,sheet_id).entry
  
  
  data= []
  for x in data_feed:
    dict ={}
    for k,v in x.custom.iteritems():
      dict[k] = v.text
    data.append(dict)
  
  # create new list with offices name
  list_offices = []
  for x in data:
    list_offices.append(x['office'])


  ## office validation ##
  while True:
    office = raw_input('what office are you calculating for?: ')
    pattern = re.search('([A-z][A-z])[(\s)(\-)(_)]([A-z][A-z][A-z])',office)
    
    try:
      office == pattern.group(0)
      
      # convert potentially mispelt office into right upper case format so that it can be verified against list_offices
      
      office1 = office.upper()
      office2 = office1.replace(' ','-')
      office3 = office2.replace('_','-')
      
      ### office permission check ###
      if office3 in list_offices:
        user_momapage = 'https://orginfo.corp.google.com/%s?format=xml' %(doc_client.email)
        user_string = UrlToText(user_momapage)
        manager = re.search(r'<manager>\w+</manager>',user_string)
        print manager
        
      else:
        print 'The office code ' + office + ' is not in the data set.'
    except AttributeError:
      print 'Invalid office code format...must be in form LL-LLL.'
    
    

    
    
      

  
  
if __name__ == '__main__':
  main()

  
  
  
  