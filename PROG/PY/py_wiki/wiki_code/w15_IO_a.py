#!/usr/bin/env python
# 15 File IO

# Write a file
out_file = open("test.txt", "wt")
out_file.write(input("Write something (nice): "))
out_file.close()

input('\n+++Saved+++\n\nPress enter to view content ')
 
# Read a file
in_file = open("test.txt", "rt")
text = in_file.read()
in_file.close()
 
print(text)
