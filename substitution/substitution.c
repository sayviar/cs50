#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

void CypherText(string text, string cypher);

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
    string text = get_string("plaintext: ");
    //string plain =
    CypherText(text, argv[1]);
    //printf("ciphertext: %s\n", plain);
    return 0;
}

void CypherText(string text, string cypher)
{
    //string cypheredText = "";
    printf("ciphertext: ");
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isupper(text[i]))
        {
            printf("%c",toupper(cypher[(int) text[i] - 64]));

        }
        else if(islower(text[i]))
        {
            printf("%c", tolower(cypher[(int) text[i] - 96]));
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}
