#! /usr/bin/python

# part 1 (manipulate strings)

old_str = 'sUpERcaLaFragaliSticeXPialaDoshuS'
new_str1 = old_str.lower()
new_str2 = old_str.upper()
new_str3 = old_str.replace('sUpER','sooopaaar')
new_str4 = old_str[5:-13]

print new_str1
print new_str2
print new_str3
print new_str4

# part 2 (print the 1st 5 iterations of the "bottles of beer" song)

num = 99
a = 'bottles of beer on the wall, ' 
b = 'bottles of beer...'
c = 'take 1 out, pass it around, '
d = 'bottles of beer on the wall.'

line1 = str(num) + ' ' + a + str(num) + ' ' + b
line2 = c + str(num - 1) + ' ' + d
line3 = str(num - 1) + ' ' + a + str(num - 1) + ' ' + b
line4 = c + str(num - 2) + ' ' + d 
line5 = str(num - 2) + ' ' + a + str(num - 2) + ' ' + b
line6 = c + str(num - 3) + ' ' + d 
line7 = str(num - 3) + ' ' + a + str(num - 3) + ' ' + b
line8 = c + str(num - 4) + ' ' + d
line9 = str(num - 4) + ' ' + a + str(num - 4) + ' ' + b
line10 = c + str(num - 5) + ' ' + d

print line1
print line2
print line3
print line4
print line5
print line6
print line7
print line8
print line9
print line10

#part 3

x = raw_input('enter an Integer: ')
y = 3
z = int(x) % y

text = 'if you divide  '
text2 = ' the remainder is '

print text + x + ' by ' + str(y) + ',' + text2 + str(z) + '!'



