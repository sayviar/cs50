#include <cs50.h>
#include <math.h>
#include <stdio.h>

void ValidCheck(string card, long cardnumber);

int main(void)
{

    long cardnumber = get_long("Number: ");
    string card;
    if (cardnumber / (long) pow(10, 13) == 34 || cardnumber / (long) pow(10, 13) == 37)
    {
        ValidCheck("AMEX\n", cardnumber);
    }
    else if (cardnumber / (long) pow(10, 14) > 50 && cardnumber / (long) pow(10, 14) < 56)
    {
        ValidCheck("MASTERCARD\n", cardnumber);
    }
    else if (cardnumber / (long) pow(10, 12) == 4 || cardnumber / (long) pow(10, 15) == 4)
    {
        ValidCheck("VISA\n", cardnumber);
    }
    else
    {
        printf("INVALID\n");
    }
}

void ValidCheck(string card, long cardnumber)
{
    int checksum = 0;
    for (long number = cardnumber / 10; number > 0; number /= 100)
    {
        if ((number % 10) * 2 > 9)
        {
            checksum += (number % 10) * 2 % 10;
            checksum += (number % 10) * 2 / 10;
        }
        else
        {
            checksum += (number % 10) * 2;
        }
    }

    for (long n = cardnumber; n > 0; n /= 100)
    {
        checksum += n % 10;
    }

    if (checksum % 10 == 0)
    {
        printf("%s", card);
    }
    else
    {
        printf("INVALID\n");
    }
}
