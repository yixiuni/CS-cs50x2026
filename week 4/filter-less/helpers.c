#include "helpers.h"
#include <math.h>
#include <stdbool.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sum = 0;
            int avr = 0;
            sum += image[i][j].rgbtRed;
            sum += image[i][j].rgbtGreen;
            sum += image[i][j].rgbtBlue;
            avr = (int) round(sum / 3.0);
            image[i][j].rgbtRed = avr;
            image[i][j].rgbtGreen = avr;
            image[i][j].rgbtBlue = avr;
        }
    }

    return;
}

int Smaller(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE copy = image[i][j];

            image[i][j].rgbtRed =
                Smaller(255, (int) round(.393 * copy.rgbtRed + .769 * copy.rgbtGreen +
                                         .189 * copy.rgbtBlue));
            image[i][j].rgbtGreen =
                Smaller(255, (int) round(.349 * copy.rgbtRed + .686 * copy.rgbtGreen +
                                         .168 * copy.rgbtBlue));
            image[i][j].rgbtBlue =
                Smaller(255, (int) round(.272 * copy.rgbtRed + .534 * copy.rgbtGreen +
                                         .131 * copy.rgbtBlue));
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {

            RGBTRIPLE tmp = image[i][j];

            image[i][j] = image[i][(width - 1 - j)];
            image[i][(width - j - 1)] = tmp;
        }
    }
    return;
}

// Blur image
bool check(int a, int b, int height, int width)
{
    if ((a >= 0 && a <= height - 1) && (b >= 0 && b <= width - 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int count = 0;
            int sum_red = 0;
            int sum_green = 0;
            int sum_blue = 0;
            for (int m = (i - 1); m <= (i + 1); m++)
            {
                for (int n = (j - 1); n <= (j + 1); n++)
                {
                    if (check(m, n, height, width))
                    {
                        sum_red += copy[m][n].rgbtRed;
                        sum_green += copy[m][n].rgbtGreen;
                        sum_blue += copy[m][n].rgbtBlue;
                        count++;
                    }
                }
            }

            image[i][j].rgbtRed = (int) round(sum_red / (double) count);
            image[i][j].rgbtGreen = (int) round(sum_green / (double) count);
            image[i][j].rgbtBlue = (int) round(sum_blue / (double) count);
        }
    }
    return;
}
