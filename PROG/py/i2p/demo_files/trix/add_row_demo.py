#!/usr/bin/python2.6

import atom
import gdata.spreadsheet.service
import getpass
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

  # Insert a row of data into trix
  row = {'ldap': 'mcumberbatch',
         'name': 'Michael Cumberbatch',
         'department': 'PTO Ops',
         'contribution': '26',
         'totalpayments-ytd': '999',
         'totalmatch': '8'}

  trix_client.InsertRow(row, trix_key, wks_id)

  print 'done.'
    
if __name__ == '__main__':
  main()
