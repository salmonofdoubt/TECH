#!/usr/bin/env python
# 13_More_Lists


things = [0, 'Fred', 2, 'S.P.A.M.', 'Stocking', 42, "Jack", "Jill"]
print(things[1])
print(things[2:4],'\n\n')

input('Press Any key to run an actual program ')
poem = ["<B>", "Jack", "and", "Jill", "</B>", "went", "up", "the",
        "hill", "to", "<B>", "fetch", "a", "pail", "of", "</B>",
        "water.", "Jack", "fell", "<B>", "down", "and", "broke",
        "</B>", "his", "crown", "and", "<B>", "Jill", "came",
        "</B>", "tumbling", "after"]
 
def get_bolds(text):
    true = 1
    false = 0
    is_bold = false  ## is_bold: tells if currently looking at bold section of text.
    start_block = 0  ## start_block: index of start of either unbolded or bolded segment of text.
    for index in range(len(text)):  ## Handle a starting of bold text
        if text[index] == "<B>":
            if is_bold:
                print("Error: Extra Bold")
            is_bold = true         ## print "Not Bold:", text[start_block:index]
            start_block = index + 1
        if text[index] == "</B>":  ## Handle end of bold text. Last number in slice is index after the last index used.
            if not is_bold:
                print("Error: Extra Close Bold")
            print("Bold [", start_block, ":", index, "]", text[start_block:index])
            is_bold = false
            start_block = index + 1
print(poem) 
get_bolds(poem)
