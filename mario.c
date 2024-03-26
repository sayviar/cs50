#include <stdio.h>
#include <cs50.h>

int main(void)
{
    do {
    int n = get_int("Height:\n");
    }
    while (n > 0 && n < 9);

    for (int i = 1; i <= n; i++)
    {
        string spaces= " " * n-i;
        string hashes = "#" * i;
        printf("%s", spaces);
        printf("%s  %s\n", hashes, hashes)
    }
}
