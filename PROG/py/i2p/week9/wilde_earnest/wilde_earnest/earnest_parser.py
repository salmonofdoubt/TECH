#! /usr/bin/python

# I was unable to iterate trhough multiple files at the same time so I had to open every single file singularly


import re

def main():
 
  d = {}
  for num in range(1,8):
    totfile = open('earnest_%d.txt'%num, 'rU')
    text_file = totfile.read()
  
    
    
    newtext = re.sub(r'<[^<]+?>', '', text_file)

    newtext1 = re.sub(r'\n\s*\n*','\n',newtext)

    newtext2 = re.sub(r'\[.+\]','',newtext1)
    
    
    words = re.findall(r'(\w+[A-Z]:)',newtext2)
  
  print words
  
  
  '''for x in character:
    d1[x] = d1.get(x,0) + 1



 
  list1 =[]
  list1.append(d1)


  result = {}
  
  for newdict in list1:
    for k in newdict:
      result[k] = result.setdefault(k,0) + newdict[k]
  
  
  print 'the character with most lines is: ' + max(result, key=result.get)'''
     











if __name__  =='__main__':
  main()

