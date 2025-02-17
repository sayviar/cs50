#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool DoubleChecker(string cypher);
void CypherText(string text, string cypher);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substituation key\n");
        return 1;
    }
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
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
    if (DoubleChecker(argv[1]))
    {
        printf("Error, each letter once!\n");
        return 1;
    }
    string text = get_string("plaintext: ");
    CypherText(text, argv[1]);
    return 0;
}
bool DoubleChecker(string cypher)
{
    for (int i = 0, n = strlen(cypher); i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (tolower(cypher[i]) == tolower(cypher[j]))
            {
                return true;
            }
        }
    }
    return false;
}

void CypherText(string text, string cypher)
{
    printf("ciphertext: ");
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isupper(text[i]))
        {
            printf("%c", toupper(cypher[(int) text[i] - 65]));
        }
        else if (islower(text[i]))
        {
            printf("%c", tolower(cypher[(int) text[i] - 97]));
        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}
