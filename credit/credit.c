#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long cardnumber;
    do
    {
        cardnumber = get_long("Number: ");
    }
    while (False);

    for (int i = 0; i % 2 == 1; i++)
        for (int number = cardnumber; number > 0; number / 10)
        {

        }
}
