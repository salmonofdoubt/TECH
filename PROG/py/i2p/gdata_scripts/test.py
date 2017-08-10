import atom
import gdata.spreadsheet.service
import getpass

def GetTrixClient():
  gd_client = gdata.spreadsheet.service.SpreadsheetsService()#1
  gd_client.email = raw_input('ldap: ') + '@google.com' #2
  gd_client.password = getpass.getpass('password:')#3 rwscukvyywucornz
  gd_client.source = 'i2p gdata demo'
  gd_client.ProgrammaticLogin() #4
  return gd_client

def main():
  # create a trix client object
  trix_client = GetTrixClient()
  
  trix_key = '0AlmG3dq3z1e6dHl6ZmJfazRfa19RQTlSMnBrOHpyeHc'
  
  # Get the worksheets feed - info for every worksheet
  worksheet_feeds = trix_client.GetWorksheetsFeed(trix_key).entry 
  
    
  #obtain the first sheet's id
  wks_id = worksheet_feeds[1].id.text.split('/')[-1]
  
  # get data out
  data_feed = trix_client.GetListFeed(trix_key,wks_id).entry

  data=[]
  for row_feed in data_feed:
    row_dict = {}
    for key,val in row_feed.custom.iteritems():
      row_dict[key] = val.text
    data.append(row_dict)

  print data

if __name__ == '__main__':
  main()