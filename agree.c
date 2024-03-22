#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char c = get_char("Do you agree? ");

    if ((c == 'y') or (c == 'Y'))
    {
        printf("Agreed.\n");
    }
    else if ((c == 'n') or (c == 'N'))
    {
        printf("Not agreed.\n");
    }
}
