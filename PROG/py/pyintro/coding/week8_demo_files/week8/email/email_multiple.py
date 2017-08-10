#!/usr/bin/python2.6

"""
  Shows how to MULTIPLE emails with Python.
  Do NOT recreate the SMTP instance.

  author: alberthwang@google.com
  course: Introduction to Programming (goto/i2p)
"""

import smtplib

from email.mime.text import MIMEText

def SendEmail(smtp, sender, recipients, subject, body):
  msg = MIMEText(body)

  msg['Subject'] = subject
  msg['From'] = sender
  msg['To'] = recipients

  smtp.sendmail(sender, recipients.split(','), msg.as_string())

  print 'sent.'

def main():
  smtp_instance = smtplib.SMTP('localhost')

  SendEmail(smtp=smtp_instance,
            sender='alberthwang@google.com',
            recipients='alberthwang@google.com',
            subject='I2P Test Email',
            body='Just testing things...')

  SendEmail(smtp=smtp_instance,
            sender='alberthwang@google.com',
            recipients='alberthwang@google.com',
            subject='I2P Test Email2',
            body='Just testing things2...')

  smtp_instance.quit()


if __name__ == '__main__':
  main()
