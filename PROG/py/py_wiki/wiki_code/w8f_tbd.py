#!/usr/bin/env python
#8_Lists - test of knowledge - ext'd



def get_questions():                        #Note that these are 3 lists 
    return [["What color is the daytime sky on a clear day? ", "blue"],
            ["What is the answer to life, the universe and everything? ", "42"],
            ["What is a three letter word for mouse trap? ", "cat"],
            ["What noise does a truly advanced machine make? ","ping"]]
  
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


#showing a list of questions and answers
def showquestions():
    q = 0
    while q < len(questions):
        a = 0
        print("Q:" , questions[q][a])
        a = 1
        print("A:" , questions[q][a])
        q = q + 1
 
# now let's define the menu function
def menu():
    print("-----------------")
    print("Menu:")
    print("1 - Take the test")
    print("2 - View a list of questions and answers")
    print("3 - View the menu")
    print("5 - Quit")
    print("-----------------")
 
choice = "3"
while choice != "5":
    if choice == "1":
        run_test(question)
    elif choice == "2":
        showquestions()
    elif choice == "3":
        menu()
    print()
    choice = input("Choose your option from the menu above: ")


 
##run_test(get_questions())                   #let's run the questions




'''
Expand the test.py program so it has menu giving the option of taking the test,
viewing the list of questions and answers, and an option to quit.
Also, add a new question to ask, "What noise does a truly advanced machine make?"
with the answer of "ping".
'''
