#include <cs50.h>
#include <stdio.h>
#include <string.h>

int add(int a, int b);


int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");
    float z = (float) x / (float) y;

    for(char i[20]= ""; strlen(i) < 10; strcat(i, "r"))
    {
        printf("%s\n", i);
    }

    printf("%f\n", z);
}


int add(int a, int b)
{
    return a + b;
}

