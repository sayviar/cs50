#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //loop over all pixels
    for (int i = 0; i< height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average;
            average = round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3.0);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i< height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;
            int sepiaRed;
            int sepiaGreen;
            int sepiaBlue;

            sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            (sepiaRed > 255) ? (image[i][j].rgbtRed = 255) : (image[i][j].rgbtRed = sepiaRed);
            sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            (sepiaGreen > 255) ? (image[i][j].rgbtGreen = 255) : (image[i][j].rgbtGreen = sepiaGreen);
            sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);
            (sepiaBlue > 255) ? (image[i][j].rgbtBlue = 255) : (image[i][j].rgbtBlue = sepiaBlue);
        }
    }


    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
        for (int i = 0; i< height; i++)
    {
        for (int j = 0; j < width/2.0; j++)
        {
            RGBTRIPLE buffer = image[i][j];
            image[i][j] = image[i][width-1-j];
            image[i][width-1-j] = buffer;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i< height; i++)
    {
        for (int j = 0; j < width/2.0; j++)
        {
            
            copy[i][j] = image[i][j]

        }
    }
    return;
}
