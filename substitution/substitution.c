#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    if (argc != 2)
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
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
}

string CypherText(string text, string cypher)
{
    string cypheredText = "";
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isupper(text[i]))
        {
            cypheredText += cypher[(int) text[i] - 64];
        }
        else if(islower)
    }
    return "s";
}
