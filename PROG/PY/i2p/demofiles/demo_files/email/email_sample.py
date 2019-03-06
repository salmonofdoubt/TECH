#!/usr/bin/python2.6

"""
  Shows how to send a basic email with Python
  - both single and multiple recipients

  author: alberthwang@google.com
  course: Introduction to Programming (goto/i2p)
"""

import smtplib

from email.mime.text import MIMEText

def SendEmail(sender, recipients, subject, body):
  msg = MIMEText(body)

  msg['Subject'] = subject
  msg['From'] = sender
  msg['To'] = recipients

  smtp_instance = smtplib.SMTP('localhost')
  smtp_instance.sendmail(sender, recipients.split(','), msg.as_string())
  smtp_instance.quit()

  print 'sent.'

def main():
  SendEmail(sender='szuppani@google.com',
            recipients='szuppani@google.comm',
            subject='WHAT IS UP?????!',
            body='Just testing things...')

  """SendEmail(sender='szuppani@google.com',
            recipients='szuppani@google.com',
            subject='I2P TEST EMAIL 2 RECIPS',
            body='Just testing things...')"""

if __name__ == '__main__':
  main()
