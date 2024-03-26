#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int checksum;
    long cardnumber;
    do
    {
        cardnumber = get_long("Number: ");
    }
    while (false);

    for (long number = cardnumber / 10; number > 0; number / 100)
    {
        if ((number % 10) *2 > 9)
        {
            checksum += number % 10;
            checksum += number / 10;
        }
        else
        {
            checksum += (number % 10) *2;
        }
    }
    for (long n = cardnumber; n > 0; n / 100)
    {
        checksum += n % 10;
    }
    if (checksum % 10 == 0)
    {
        printf("VALID");
    }
    else
    {
        printf("INVALID");
    }
}
