#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int checksum = 0;
    long cardnumber = get_long("Number: ");
    string card;
    bool cardcheck = false;
    if (cardnumber / 10 * 14 == 34 || cardnumber / 10 * 14 == 37)
    {
        card = "AMEX\n";
        
    }
    else if (cardnumber / 10 * 15 > 50 && cardnumber / 10 * 15 < 56)
    {
        card = "MASTERCARD\n";
    }
    else if (cardnumber /)

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
