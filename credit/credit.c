#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int secondtolast;
    long cardnumber;
    do
    {
        cardnumber = get_long("Number: ");
    }
    while (False);

    for(int i = 0; i % 2 = 1; i++)
    {
        secondtolast += cardnumber % 10 * i
    }

    for (int number = cardnumber / 10; number > 0; number / 100)
    {
        secondtolast += (number % 10) * 2
    }
}
