#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int checksum = 0;
    long cardnumber = get_long("Number: ");

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
    if ((checksum % 10 == 0 && cardnumber / 10 * 14 == 34) || cardnumber /)
    {
        printf("VALID\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
