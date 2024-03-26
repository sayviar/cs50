#include <stdio.h>
#include <cs50.h>

int calculate25(int change);
int calculate10(int change);
int calculate5(int change);
int calculate1(int change);
int main(void)
{
    int change = get_int("Change owed: ");
    int minimumCoins = 0;
    minimumCoins += calculate25(change);
    minimumCoins += calculate10(change);
    minimumCoins += calculate5(change);
    minimumCoins += calculate1(change);
    printf("%i\n", minimumCoins);


}

int calculate25(int change)
{
    int coins = 0;
    while (change > 25)
    {
        coins++;
        change -= 25;
    }
    return coins;
}

int calculate10(int change)
{
    int coins = 0;
    while(change > 10)
    {
        coins++;
        change -= 10;
    }
    return coins;
}

int calculate5(int change)
{
    int coins = 0;
    while(change > 5)
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


