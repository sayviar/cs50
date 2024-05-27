from cs50 import get_int

while True:
    size = get_int("Size of Pyramid (Size must be between 1 and 8): ")
    if size >= 1 and size <= 8:
        break

for i in range(size):
    print(" " * (size - 1 - i), end="")
    print("#" * (i + 1) + "  " + "#" * (i + 1))


