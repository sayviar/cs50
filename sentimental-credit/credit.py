from cs50 import get_string
import re

def main():
    while True:
        card_number = get_string("Number: ")
        if card_number.isnumeric():
            break
    if re.search("^(34|37)[0-9]{13}$", card_number):
        if check_credit(card_number):
            print("AMEX\n")
        else:
            print("INVALID\n")
    elif re.search("^(5[1-5][0-9]{14})$", card_number):
        if check_credit(card_number):
            print("MASTERCARD\n")
        else:
            print("INVALID\n")
    elif re.search("^((4)[0-9]{12}|[0-9]{15})$", card_number):
        if check_credit(card_number):
            print("VISA\n")
        else:
            print("INVALID\n")
    else:
        print("INVALID\n")


def check_credit(credit_number):
    length = len(credit_number)
    checksum = 0
    checkstring = ""
    for i in range(length-2, -1, -2):
        checkstring += str(2 * int(credit_number[i]))
    for i in checkstring:
        checksum += int(i)
    for i in range(length-1, -1, -2):
        checksum += int(credit_number[i])

    print(checksum)
    if checksum % 10 == 0:
        return True
    else:
        return False
main()



