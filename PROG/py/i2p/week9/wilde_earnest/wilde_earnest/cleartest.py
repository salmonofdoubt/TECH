import re

d1 = {}


text1 = open('earnest_1.txt','r').read()

newtext = re.sub(r'<[^<]+?>', '', text1)

newtext1 = re.sub(r'\n\s*\n*','\n',newtext)

newtext2 = re.sub(r'\[.+\]','',newtext1)




new2 = re.findall(r'(\w+)',newtext2)
new3 = re.findall(r'(\w+[A-Z])',newtext2)
new4 = re.findall(r'\w+',newtext2)

list = ['ALGERNON','this is the game',
        'JACK', 'I have tickets']

for k,v  in enumerate(list):
  if v in new3:
    d1[v] = list[k+1]


for k,v in enumerate(new4):
  if v in new3:
    d1[v] = new4[k+1]

print d1