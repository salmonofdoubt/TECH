#!/usr/bin/python2.4

import csv
import smtplib

from email.mime.text import MIMEText

def SendEmail(smtp, sender, recipients, subject, body):
  msg = MIMEText(body)

  msg['Subject'] = subject
  msg['From'] = sender
  msg['To'] = recipients

  smtp.sendmail(sender, [recipients], msg.as_string())


def main():

  smtp_instance = smtplib.SMTP('localhost')

  data_file = open('testscores.csv', 'rU')
  dictReader_data = csv.DictReader(data_file)
  dict_data = {}
  
  for row_dict in dictReader_data:
    dict_data[row_dict['LDAP']] = row_dict

  # Determine class average
  score_list = []
  for ldap, data in dict_data.iteritems():
    score_list.append(int(data['SCORE']))
  class_average = sum(score_list)/float(len(score_list))

 
  for ldap, data in dict_data.iteritems():
    # Determine first name
    split_name = data['FULLNAME'].split(' ')
    first_name = split_name[0]
    
    # Construct email
    greeting_text = 'Hi ' + first_name + '! \n \n'
    score_text = 'You got a ' + data['SCORE'] + '% on your Final Exam.'
    average_text = 'The average score was ' + str(class_average) + '%.'
    if int(data['SCORE']) < class_average:
      relative_score = 'below'
    elif int(data['SCORE']) > class_average:
      relative_score = 'above'
    else:
      relative_score = 'at'
    relative_text = 'This means that you scored ' + relative_score + ' the average.\n \n'
    location_text = 'You can pick up your test in the lobby of ' + data['LOCATION'] + '. \n \n'
    footer_text = '*Note: this is a homework assignment for a programming course I am in. '
    footer_text += 'Please disregard!'
    
    full_email = greeting_text + score_text + average_text
    full_email += relative_text + location_text + footer_text
    
    # Send email
    SendEmail(smtp=smtp_instance,
              sender='dianev@google.com',
              recipients= ldap + '@google.com',
              subject='Your Exam results',
              body= full_email)
              
  smtp_instance.quit()
  
  
if __name__ == '__main__':
  main()