#include <cs50.h>
#include <stdio.h>
#include <stdint.h>

int checkpdf (uint8_t a[4],uint8_t b[4]);

const int CHECK_SIZE = 4;
uint8_t pdf[] = {37, 80, 68, 70};


int main (int argc, string argv[])
{
    // TODO: Check first four bytes in given file
    if (argc != 2)
    {
        printf("The right format is ./pdf file\n");
        return 1;
    }
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open File!\n");
        return 1;
    }
    uint8_t buffer[CHECK_SIZE];

    fread(buffer, 1, 4, input);

    for(int i = 0 ; i < 4; i++)
    {
        printf("%i\n", buffer[i]);
    }

    if (checkpdf(buffer, pdf))
    {
        printf("This is a pdf\n");
    }
    else
    {
        printf("This is not a pdf\n");
    }
    fclose(input);
}

int checkpdf (uint8_t a[4],uint8_t b[4])
{
    for (int i = 0; i<4; i++)
    {
        if (a[i] != b[i])
        {
            return false;
        }
    }
    return true;
}
