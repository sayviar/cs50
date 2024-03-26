#include <cs50.h>
#include <stdio.h>

void ValidCheck(string card, long cardnumber);

int main(void)
{

    long cardnumber = get_long("Number: ");
    string card;
    if (cardnumber / 10 * 14 == 34 || cardnumber / 10 * 14 == 37)
    {
        ValidCheck("AMEX\n", cardnumber);
    }
    else if (cardnumber / 10  15 > 50 && cardnumber / 10 * 15 < 56)
    {
        ValidCheck("MASTERCARD\n", cardnumber);
    }
    else if (cardnumber / 10 * 13 == 4 || cardnumber / 10 * 16 == 4)
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
        if ((number % 10) *2 > 9)
        {
            checksum += (number % 10) * 2 % 10;
            checksum += (number % 10) * 2 / 10;
        }
        else
        {
            checksum += (number % 10) *2;
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
