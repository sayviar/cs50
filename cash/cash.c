#include <cs50.h>
#include <stdio.h>

int calculate25(int change);
int calculate10(int change);
int calculate5(int change);
int calculate1(int change);
int main(void)
{
    int change;
    do
    {
        change = get_int("Change owed: ");
    }
    while (change < 0);
    int quarters = calculate25(change);
    change -= quarters * 25;
    int dimes = calculate10(change);
    change -= dimes * 10;
    int nickles = calculate5(change);
    change -= nickles * 5;
    int pennys = calculate1(change);
    change -= pennys * 1;
    int minimumCoins = quarters + dimes + nickles + pennys;
    printf("%i\n", minimumCoins);
}

int calculate25(int change)
{
    int coins = 0;
    while (change >= 25)
    {
        coins++;
        change -= 25;
    }
    return coins;
}

int calculate10(int change)
{
    int coins = 0;
    while (change >= 10)
    {
        coins++;
        change -= 10;
    }
    return coins;
}

int calculate5(int change)
{
    int coins = 0;
    while (change >= 5)
    {
        coins++;
        change -= 5;
    }
    return coins;
}

int calculate1(int change)
{
    return change;
}
