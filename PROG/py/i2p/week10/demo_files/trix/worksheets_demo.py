#!/usr/bin/python2.6

import atom
import gdata.spreadsheet.service
import getpass

def GetTrixClient():
  gd_client = gdata.spreadsheet.service.SpreadsheetsService()
  gd_client.email = raw_input('ldap: ') + '@google.com'
  gd_client.password = getpass.getpass('password:')
  gd_client.source = 'i2p gdata demo'
  gd_client.ProgrammaticLogin()
  return gd_client

def main():
  # Create a trix client object
  trix_client = GetTrixClient()

  trix_key = 'tyzfb_k4_k_QA9R2pk8zrxw'

  # Get the worksheets feed - info for every worksheet
  worksheet_feeds = trix_client.GetWorksheetsFeed(trix_key).entry

  # For each worksheet, print its title and full ID url
  for worksheet_feed in worksheet_feeds:
    print worksheet_feed.title.text
    print worksheet_feed.id.text
    #print ''

    # This is the worksheet ID we'll need
    print worksheet_feed.id.text.split('/')[-1]
    print ''

  # Obtain a worksheet's ID through its worksheet number
  print worksheet_feeds[0].id.text.split('/')[-1]
 
if __name__ == '__main__':
  main()
