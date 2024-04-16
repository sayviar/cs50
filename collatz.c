#include <cs50.h>
#include <stdio.h>

int collatz_count = 0;
void collatz(int n);
int main (void)
{
    collatz(get_int("Type int:"));
    printf("%i\n", collatz_count);
    return 0;
}

void collatz(int n)
{
    if (n == 1)
    {
        return;
    }
    else if (n % 2 == 0)
    {
        collatz(n/2);
        collatz_count++;

    }
    else
    {
        collatz(3* n +1);
        collatz_count++;
    }
}
