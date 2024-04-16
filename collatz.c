#include <cs50.h>
#include <stdio.h>

int collatz_count = 0;
void main (void)
{
    collatz(get)
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
        collatz++;

    }
    else
    {
        collatz(3* n +1);
        collatz++;
    }
}
