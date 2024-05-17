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
            int sepiaRed;
            int sepiaGreen;
            int sepiaBlue;

            sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            (sepiaRed > 255) ? (image[i][j].rgbtRed = 255) : (image[i][j].rgbtRed = sepiaRed);
            sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            (sepiaGreen > 255) ? (image[i][j].rgbtGreen = 255) : (image[i][j].rgbtGreen = sepiaGreen);
            sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
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
            image[i][j] = image[i][width-j];
            image[i][width-j] = buffer;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
