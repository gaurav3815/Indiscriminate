Account_Balance = float(200)
Cash_Balance = float(20.50)
Vending_Machine = float(300)
vending_keys = ["a1", "a2", "a3", "a4", "a5"]
payment_method_word = ["Card", "cash", "card", "Cash"]
cash_payment = ["cash", "CASH", "Cash"]
card_payment = ["Card", "card"]
a1_stock = 2
a2_stock = 4
a3_stock = 5
a4_stock = 7
a1 = float(1.50) #Crips
a2 = float(2.00) #Apple Juice
a3 = float(2.50) #Banana Milkshake
a4 = float(1.80) #KitKat
while True:
    user_input = input("Please enter a Value = ")
    while user_input not in vending_keys:
        print("Couldn't Recognise the Value!")
        user_input = input("Please enter a Value = ")
    else:
        if user_input == "a1":
            if a1_stock == 0:
                print("Crips are out of Stock!")
            else:
                print("Crips")
                print("Payment :",a1)
                payment_method = input("Card or Cash? \n =")
                while payment_method not in payment_method_word:
                    print("Couldn't Recognise the Payment Method, Try again")
                    payment_method = input("Card or Cash? \n =")
                else:
                    if payment_method in card_payment:
                        if Account_Balance >= a1:
                            Account_Balance = Account_Balance - a1
                            print("Payment Sucessful")
                            print(Account_Balance)
                            a1_stock = a1_stock - 1
                            print(a1_stock)
                        else:
                            print("You Don't Have enough funds")
                    else:
                        cash_input = float(input("Money amount = £"))
                        if cash_input == a1:
                            Cash_Balance = Cash_Balance - a1
                            print("Payment Sucessful")
                            print(Cash_Balance)
                        elif cash_input < a1:
                            print("Not enough, Pay", a1 - cash_input,"more.")
                        else:
                            while cash_input > Vending_Machine:
                                print("Not enough funds on Machine for change enter less")
                                cash_input = float(input("Money amount = £"))
                            else:
                                change = cash_input - a1
                                print("Your Change : £",change)
                                Vending_Machine = Vending_Machine - change
