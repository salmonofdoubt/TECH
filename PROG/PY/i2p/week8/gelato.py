
import smtplib

from email.mime.text import MIMEText

import csv

def SendEmail(sender,recipients,subject,body):
  msg = MIMEText(body)
	
  msg['Subject'] = subject
  msg['From'] = sender
  msg['To'] = recipients
	
  smtp_istance = smtplib.SMTP('localhost')
  smtp_istance.sendmail(sender,recipients.split(','),msg.as_string())
  

  print 'sent'


def main():
  data_file = open('gelato.csv','w')
  field_names = ['ldap','full name','score','location']
  data_writer = csv.DictWriter(data_file,field_names)
  
  header_row = {'ldap':'ldap',
  		'full name':'full name',
  		'score':'score',
		'location':'location'}

  row1 = {'ldap':'alberthwang',
  	  'full name': 'Albert Hwang',
  	  'score':'11',
          'location':'US-MTV-CL5'}
  row2 = {'ldap':'satishm',
  	  'full name': 'Satish Musurunu	',
  	  'score':'60',
  	  'location':'US-MTV-40'}
  row3 = {'ldap':'smadaan',
  	  'full name': 'Saurabh Madaan',
  	  'score':'40',
	  'location':'US-MTV-CL5'}
  row4 = {'ldap':'tiffanyliu',
  	  'full name': 'Tiffany Liu',
  	  'score':'90',
  	  'location':'US-MTV-43'}
  row5 = {'ldap':'ninaye',
  	  'full name': 'Nina Ye	',
  	  'score':'49',
  	  'location':'US-MTV-CL5'}
	
  data = [header_row,row1,row2,row3,row4,row5]
  data_writer.writerows(data)
	
  body_text  = 'Hi {0}!\n\n\
  You got a {1} % on your Final Exam. The average score was {2} %.\n\n\
  This means that you scored {3} the average. \n\n\
  You can pick up your test in the lobby of {4}\n\n\
  *Note: this is a homework assignment for a programming course I am in. Please disregard!'	
  
  my_list = []
  for x in data[1:]:
    my_list.append(x['score'])
    my_list2 = map(int,my_list)

  average = sum(my_list2)/len(my_list) 
  
  if my_list2[0] < average:
    text1 = 'below'
  elif my_list[0] > average:
    text2 = 'above'  
	
  SendEmail(sender = 'szuppani@google.com',
            recipients = 'saveriozuppani@gmail.com',
	    subject = 'I2P email test',
	    body = body_text.format(data[1]['full name'].replace('Hwang',''),    
                                    data[1]['score'],             
                                    average,
                                    text1,
                                    data[2]['location']))


  SendEmail(sender = 'szuppani@google.com',
	    recipients = 'saveriozuppani@gmail.com',
            subject = 'I2P email test2',
            body = body_text.format(data[2]['full name'].replace('Musurunu',''),
                                    data[2]['score'],
                                    average,
                                    "above",
                                    data[2]['location']))




if __name__ == '__main__':
	main()
