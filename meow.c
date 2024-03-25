#include <stdio.h>

void meow(void);

int main (void)
{
    meow(4);
}

void meow(int n)
{
    for (int i = 0; i < n; i++)
    {
    printf("meow\n");
    }
}
