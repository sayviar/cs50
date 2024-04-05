#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(string cypher)
{
    bool onlyLetters = true;

    for (int i = 0, n = strlen(cypher); i < n ; i++)
    {
        if (!isalpha(cypher[i]))
        {
            printf("Usage: ./substituation key");
            return 1;
        }
    }
}
