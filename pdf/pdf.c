#include <cs50.h>
#include <stdio.h>
#include <stdint.h>

int checkpdf (int a[4], int b[4]);

const int CHECK_SIZE = 4;
int pdf[] = {37, 80, 68, 70};


int main (int argc, string argv[])
{
    // TODO: Check first four bytes in given file
    if (argc != 2)
    {
        printf("The right format is ./pdf file");
        return 1;
    }
    FILE *input = fopen(argv[2], "r");
    if (input == NULL)
    {
        printf("Could not open File!");
        return 1;
    }
    int buffer[CHECK_SIZE];
    for (int i = 0; i<CHECK_SIZE; i++)
    {
        fread(buffer, 1, 1, input);
    }

    if (checkpdf(buffer, pdf))
    {
        printf("This is a pdf");
    }
    else
    {
        printf("This is not a pdf");
    }
    fclose(input);
}

int checkpdf (int a[4], int b[4])
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
