#!/usr/bin/python2.6

import atom
import gdata.spreadsheet.service
import getpass
import pprint
import re

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

  # Obtain a worksheet's ID through its worksheet number
  wks_id = worksheet_feeds[0].id.text.split('/')[-1]

  # Get data out of worksheet with List-based feed
  data_feed = trix_client.GetListFeed(trix_key, wks_id).entry

  # Show what's in the row feeds
  #data = []
  """for row_feed in data_feed:
    print 'Title: ' + row_feed.title.text
    print 'Content: ' + row_feed.content.text
    print 'Custom Content: ' + str(row_feed.custom)
    print ''"""

  # Map data in a row to a dict, and everything to list of dicts
  data = []

  for row_feed in data_feed:
    row_dict = {}
    for key, val in row_feed.custom.iteritems():
      row_dict[key] = val.text
    data.append(row_dict)

  # Data in trix as a list of dicts
  pprint.pprint(data)
 
if __name__ == '__main__':
  main()
