#!/usr/bin/env python
# 14_More_Strings


print('1. Shout something\n----------------------------')


def shout(string):
    for character in string:
        print("Gimme a " + character)
        print("'" + character + "'")

shout(input("shout what? "))

print('\n')
input('enter any key to proceed')


print('2. Find middle string\n----------------------------')

def middle(string):
    print("The middle character is:", string[len(string) // 2])
 
middle(input("1.: "))
middle(input("2.: "))
middle(input("3.: "))

print('\n')
input('enter any key to proceed')


print('3. Convert all to upper case\n----------------------------')

new_text = input('Enter text: ')
def to_upper(string):
    upper_case = ''
    for character in string:
        if 'a' <= character <= 'z':
            location = ord(character) -ord('a')
            new_ascii = location + ord('A')
            character = chr(new_ascii)
        upper_case = upper_case +character
    return upper_case

print(to_upper(new_text))
print('\n')
input('end of program')




