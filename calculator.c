#include <cs50.h>
#include <stdio.h>
#include <string.h>

int add(int a, int b);


int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");

    for(char i[20]= ""; strlen(i) < 10; strcat(i, "r"))
    {
        printf("%s\n", i);
    }

    printf("%i\n", add(x, y));
}


int add(int a, int b)
{
    return a + b;
}

