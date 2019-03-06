#! /usr/bin/python

class SuperString:
  def __init__(self,BaseString,total_vowels):
    self.BaseString = BaseString
    self.total_vowels = total_vowels
    
    vowels = []
    for x in self.BaseString:
      y = ['a','e','i','o','u']
      if x in y:
        vowels.append(x)
      self.total_vowels = int(len(vowels)+1)
  
  def Replacer(self,value1,value2):
    self.value1 = value1
    self.value2 = value2
    list4 = []
    for i,v in enumerate(self.BaseString):
      if self.BaseString.find(self.value1,i) == i:
        list4.append(i)
  	
    list5 = list(self.BaseString)
  	
    if len(self.value1) < 2:
      for i,v in enumerate(list5):
        for x in list4:
          list5[x] = self.value2
		
    if len(self.value1) >1:
      for i,v in enumerate(list5):
        for x in list4:
          list5[x],list5[x+1] = self.value2
  	
    new_s1 = ''.join(list5)
    return new_s1
		
  def Spliter(self,value1):
    self.value1 = value1
		
    list2 = []
    list3 = []
    for n in xrange(len(self.BaseString)):
      if self.BaseString.find(self.value1, n) == n:
        list2.append(n)
		
    if len(self.value1) < 2:
      first = self.BaseString[0:(list2[0])]
      second = self.BaseString[(list2[0] +1):(list2[1])]
      third = self.BaseString[(list2[1] + 1):(len(self.BaseString))]
      list3.append(first)
      list3.append(second)
      list3.append(third)
    else:
      first = self.BaseString[0:(list2[0])]
      second = self.BaseString[(list2[0] +2):(list2[1])]
      third = self.BaseString[(list2[1] + 2):(len(self.BaseString))]
      list3.append(first)
      list3.append(second)
      list3.append(third)
		
		
    return list3
		
		
my_super = SuperString('albert,salbUwei,hwang',' ')
print my_super.total_vowels
print my_super.Replacer('a', 'E')
print my_super.Replacer('lb', 'YX')
print my_super.Spliter(',')
print my_super.Spliter('lb')

print '\nTesting Overlapping Patterns'
new_super = SuperString('teee','')
print new_super.Replacer('ee','me')
