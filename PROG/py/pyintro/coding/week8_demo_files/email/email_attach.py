#!/usr/bin/python2.6

"""
  Shows how to send an email with an attachment.

  author: alberthwang@google.com
  course: Introduction to Programming (goto/i2p)
"""

import smtplib

from email.MIMEMultipart import MIMEMultipart
from email.MIMEBase import MIMEBase
from email.MIMEText import MIMEText
from email import Encoders

def SendEmail(sender, recipients, subject, body, file_path):
  # Email content as multipart
  msg = MIMEMultipart()

  # Add headers
  msg['Subject'] = subject
  msg['From'] = sender
  msg['To'] = recipients

  # Add the body of the email
  msg.attach(MIMEText(body))

  # Create attachment and add to email
  attachment = MIMEBase('application', 'octet-stream')
  attachment.set_payload(open(file_path,'rb').read())
  Encoders.encode_base64(attachment)
  attach_header = 'attachment; filename="' + file_path + '"'
  attachment.add_header('Content-Disposition', attach_header)
  msg.attach(attachment)

  # Send email
  smtp_instance = smtplib.SMTP('localhost')
  smtp_instance.sendmail(sender, recipients.split(','), msg.as_string())
  smtp_instance.quit()

  print 'sent.'

def main():
  SendEmail(sender='alberthwang@google.com',
            recipients='alberthwang@google.com',
            subject='I2P Test Email - Attachments',
            body='Just testing things...',
            file_path='test.txt')

if __name__ == '__main__':
  main()
