#include <stdio.h>
#include <cs50.h>

int minimumCoins(int change);
int main(void)
{
    int change = get_int("Change owed: ");

}

int calculate25(int change)
{
    int coins;
    while (change > 25)
    {
        coins++;
        change -= 25;
    }
    return coins;
}

int calculate10(int change)
{
    int coins;
    while(change > 10)
    {
        coins++;
        change -= 10;
    }
}

int calculate5(int change)
{
    int coins;
    while(change > 5)
    {
        coins++;
        change -= 5;
    }
}

