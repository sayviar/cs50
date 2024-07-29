from cs50 import get_string
import re

def main():
    while True:
        card_number = get_string
        if card_number.isnumeric():
            break
    if re.search(")


def check_credit(credit_number):
    length = len(credit_number)
    checksum = 0
    counter = 0
    for i in range(length, 0, -1):
        if counter % 2 == 0:
            checksum += i
        else:
            checksum += i * 2
    if checksum % 10 == 0:
        return True
    else:
        return False




