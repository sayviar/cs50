from cs50 import get_int

while True:
    size = get_int("Size of Pyramid (Size must be between 1 and 8): ")
    if size >= 1 and size <= 8:
        break

for i in range(size):
    for j in reversed(range(size)):
        print(" ", end="")
    print("#" * (i + 1))


