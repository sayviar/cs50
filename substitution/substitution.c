#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    bool onlyLetters = true;

    if (argc != 1)
    {
        printf("Usage: ./substituation key\n");
        return 1;
    }
    for (int i = 0, n = strlen(argv[1]); i < n ; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Usage: ./substituation key\n");
            return 1;
        }
    }
}
