import random
import sys
highestscore = [0]
currentscore = [0]
positive_responses = ["yes", "yep", "Yes", "YES"]
negative_responses = ["No", "no", "na", "cba", "nope"]
responses = ["No", "no", "na", "cba", "nope", "yes", "yep", "Yes", "YES"]
Level1 = 4
Level2 = 8
def level2():
    print("Level 2")
    while sum(currentscore) <= Level2:
        num3 = random.randint(10, 20)
        num4 = random.randint(10, 20)
        operators = ['+', "-", "*"]
        random_operators = random.choice(operators)
        print(num3, random_operators, num4)
        add = num3 + num4
        subtract = num3 - num4
        multiply = num3 * num4
        answer = int(input("Enter a Number : "))
        if random_operators == "+" or "-" or "*":
            if random_operators == "+":
                if answer == add:
                    print("Correct!")
                    currentscore.append(1)
                    print("Your Current Score =", sum(currentscore))
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
        print("You Beat our Game!")
def level1():
    while sum(currentscore) <= Level1:
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
        return level2()
level1()
