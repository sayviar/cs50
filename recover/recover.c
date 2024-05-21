#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("The usage is ./recover infile\n");
        return 1;
    }
    // Open the memory card
    char *infile = argv[1];
    FILE *recover = fopen(infile, "r");
    if (recover == NULL)
    {
        printf("File couldn't be opened\n");
        return 1;
    }
    FILE *img = NULL;
    char *filename = malloc(4);
    int counter = 0;
    uint8_t buffer[512];
    // While there's still data left to read from the memory card
    while (fread(buffer,1,512, recover) == 512)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {

            if(img != NULL)
            {
                fclose(img);
                counter++;

            }
            sprintf(filename, "%03i.jpg", counter);
            img = fopen(filename,"w");
            if (img == NULL)
            {
                return 1;
            }



        }
        if (img != NULL)
        {
            fwrite(buffer, 1, 512, img);
        }
    }
        // Create JPEGs from the data
    fclose(img);
    fclose(recover);
    free(filename);
}
