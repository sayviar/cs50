from cs50 import get_string


def main():
    text = get_string("Text: ")
    letter = 0
    word = 0
    sentence = 0
    for i in text:
        if i.isalpha():
            letter += 1
        elif i.isspace():
            word += 1
        elif i in ['.', '!', '?']:
            sentence += 1
    word += 1

    l = letter / word * 100
    s = sentence / word * 100
    liau = (0.0588 * l) - (0.296 * s) - 15.8
    if round(liau) > 0 and round(liau) < 16:
        print(f"Grade {round(liau)}")
    elif round(liau) >= 16:
        print("Grade 16+")
    else:
        print("Before Grade 1")


main()
