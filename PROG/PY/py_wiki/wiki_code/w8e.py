#!/usr/bin/env python
#8_Lists - test of knowledge


def get_questions():                        #Note that these are 3 lists 
    return [["What color is the daytime sky on a clear day? ", "blue"],
            ["What is the answer to life, the universe and everything? ", "42"],
            ["What is a three letter word for mouse trap? ", "cat"]]
  
def check_question(question_and_answer):    #what element is the q, which one the a
    question = question_and_answer[0]   
    answer = question_and_answer[1]
    given_answer = input(question)          #give the question to the user
    if answer == given_answer:              #compare the user's answer to the testers answer
        print("Correct")
        return True
    else:
        print("Incorrect, correct was:", answer)
        return False
 
def run_test(questions):                    #runs through all the questions
    if len(questions) == 0:
        print("No questions were given.")
        return                              #the return exits the function
    index = 0
    right = 0
    while index < len(questions):
        if check_question(questions[index]):        # Check the question, it extracts a q and a list from the lists of lists.
            right = right + 1
        index = index + 1                           # go to the next question
    print("You got", right * 100 / len(questions),  # order of the computation, first multiply, then divide
           "% right out of", len(questions))
 
run_test(get_questions())                   #let's run the questions


