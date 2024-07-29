from cs50 import get_string
    letter = 0
    word = 0
    sentence = 0
def main():
    text = get_string("Text: ")
    counters(text)
    l = letter  / word * 100
    s = word  / sentence * 100
    liau = 0.0588 * l - 0.296 * s - 15.8

def counters(text):
    for i in text:
        if i.isalpha():
            letter += 1
        elif i.isspace():
            word += 1
        elif i in ['.', '!', '?']:
            sentence += 1

    return True
