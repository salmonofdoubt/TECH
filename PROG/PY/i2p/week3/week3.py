#! /usr/bin/python
a = 1
while True:
  prefix = 'the number is'
  if a == 1 : suffix = ', that is the best'
  elif a == 2 : suffix = ", that's the type of pencil you use in SAT"
  elif a == 3 : suffix = ", that rhymes with 'me'"
  elif a == 4 : suffix = ', I want some more'
  elif a == 5 : suffix = ', I like a high five!'
  elif a == 6 : suffix = ', what a neat trick...'
  else:break
  print prefix + ' ' + str(a) + suffix
  a += 1

# part 2 (re-write the bottles of beer)


bottles_number = 99
text1 = '%s bottles of beer on the wall, %s bottles of beer...'
text2 = 'Take one out, pass it around, %s bottles of beer on the wall!'


text3 = 'NINETY TWO IS LUCKY!'
text4 = 'YAY...even number of bottles!'


while bottles_number > 0:
  print ''
  print text1 % (bottles_number,bottles_number)
  print text2 % (bottles_number -1)  
    
  if (bottles_number -1) == 92:
    print text3
  
  elif ((bottles_number -1)% 2) == 0:
    print text4


  if (bottles_number -1) == 84:
    print ''
    print "oh man, I really can't have any more!"
    break	
	 
  bottles_number -= 1

	
	
