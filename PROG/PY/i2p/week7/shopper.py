#! /usr/bin/python


import datetime

def main():
  list_items = []
  forbiddenitems = ['beer','liquor','wine']
  for x in range(5):
    item = raw_input('enter product name: ')
    list_items.append(item)

    if item in forbiddenitems:
      birthday = datetime.datetime.strptime((raw_input('enter your birthday (dd/mm/year): ')),'%d/%m/%Y')

      this_moment = datetime.datetime.now()
      age = datetime.timedelta(weeks = (52*21))

      time_diff = this_moment - birthday
      if time_diff < age:
        print ' you are too young!'

        for x in forbiddenitems:
          if x in list_items:           
            list_items.remove(x)                
      else:             
        print 'thanks and enjoy'
  print list_items
			
		
if __name__ == '__main__':
	main()
