import random
import sys
highestscore = [0]
currentscore = [0]
Level1 = 30
def level1():
    positive_responses = ["yes", "yep", "Yes", "YES"]
    negative_responses = ["No", "no", "na", "cba", "nope"]
    responses = ["No", "no", "na", "cba", "nope", "yes", "yep", "Yes", "YES"]
    while sum(currentscore) < Level1:
        num1 = random.randint(0, 10)
        num2 = random.randint(0, 10)

        operators = ['+', "-", "*"]
        random_operators = random.choice(operators)
        print(num1, random_operators, num2)
        add = num1 + num2
        subtract = num1 - num2
        multiply = num1 * num2
        answer = int(input("Enter a Number : "))
        if random_operators == "+" or "-" or "*":
            if random_operators == "+":
                if answer == add:
                    print("Correct!")
                    currentscore.append(1)
                    print("Your Current Score =", sum(currentscore))
                    if sum(currentscore) > 2:
                        print("Level 2")
                else:
                    print("Inncorrect")
                    highestscore.append(sum(currentscore))
                    print("Your Highest Score is :", max(highestscore))
                    del currentscore[:]
                    user_question = input("Do you want to Play again? \n = ")
                    while user_question not in responses:
                        print("Didn't Quite Catch that!")
                        user_question = input("Do you want to Play again? \n = ")
                    else:
                        if user_question in positive_responses:
                            return level1()
                        elif user_question in negative_responses:
                            print("Game over!")
                            sys.exit()
            elif random_operators == "-":
                if answer == subtract:
                    print("Correct!")
                    currentscore.append(1)
                    print("Your Current Score =", sum(currentscore))
                    if sum(currentscore) > 2:
                        print("Level 2")
                else:
                    print("Inncorrect")
                    highestscore.append(sum(currentscore))
                    print("Your Highest Score is :", max(highestscore))
                    del currentscore[:]
                    user_question = input("Do you want to Play again? \n = ")
                    while user_question not in responses:
                        print("Didn't Quite Catch that!")
                        user_question = input("Do you want to Play again? \n = ")
                    else:
                        if user_question in positive_responses:
                            return level1()
                        elif user_question in negative_responses:
                            print("Game over!")
                            sys.exit()
            else:
                if answer == multiply:
                    print("Correct!")
                    currentscore.append(1)
                    print("Your Current Score =", sum(currentscore))
                    if sum(currentscore) > 2:
                        print("Level 2")
                else:
                    print("Inncorrect")
                    highestscore.append(sum(currentscore))
                    print("Your Highest Score is :", max(highestscore))
                    del currentscore[:]
                    user_question = input("Do you want to Play again? \n = ")
                    while user_question not in responses:
                        print("Didn't Quite Catch that!")
                        user_question = input("Do you want to Play again? \n = ")
                    else:
                        if user_question in positive_responses:
                            return level1()
                        elif user_question in negative_responses:
                            print("Game over!")
                            sys.exit()
        else:
            print("Error")
    else:
        print("You win!")
level1()
