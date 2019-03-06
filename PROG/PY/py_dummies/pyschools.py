

2/





1/13 - %operator
# Write a function that does a decimal to hexadecimal conversion.
# Hint: Make use of "%x" for hexadecimal format.
def dec2hex(num):
 hexa = "%X" % num
 return hexa
 

1/12 + complex numbers
# Compute the sum and product of 2 complex numbers:
# (2+3j) and (4+5j)
a = complex(2+3j)
b = complex(4+5j)
sum_ab = a+b 
prod_ab = a*b

sum_ab
(6+8j)

prod_ab
(-7+22j)


1/9 + 
# Use one or more string methods in above examples, extract the substring
# surrounded by 'xyz' at the beginning and end. Replace the ',' in the substring with '|'.
# and remove all trailing space.

str1  = 'abcefghxyzThis,is,the,target,string  xyzlkdjf'
idx1 = str1.find('xyz')                    # get the position of 'xyz'
idx2 = str1.find('xyz', idx1+1)            # get the next 'xyz'
str1 = str1[idx1+3:idx2].replace(',','|')    # replace ',' with '|'
str1 = str1.strip( )                             # strip trailing spaces. 

print str1
This|is|the|target|string


1/8 - Private Test Cases Failed
# Write a function, given a string of characters, return the string together with '_'s of the same length.
def underline(title): 
 s = "hello"
 t = len(s)
 s = s + "\n" + "_"*t
 return s
 
	




