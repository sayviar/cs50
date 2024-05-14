#include <cs50.h>
#include <stdio.h>
#include <stdint.h>

const int CHECK_SIZE = 4;
int main (int argc, string argv[])
{
    // TODO: Check first four bytes in given file
    if (argc != 2)
    {
        printf("The right format is ./pdf file")
        return 1;
    }
    FILE *input = fopen(argv[2], "r")
    if (input == NULL)
    {
        printf("Could not open File!")
        return 1;
    }
    

}
