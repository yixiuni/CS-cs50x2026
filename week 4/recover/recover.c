#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // While there's still data left to read from the memory card
    uint8_t buffer[512];
    int i = 0;
    char filename[8];
    FILE *photo;
    while (fread(buffer, 1, 512, card) == 512)
    {

        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[3] >= 0xe0 && buffer[3] <= 0xef))
        {

            sprintf(filename, "%03d.jpg", i);
            photo = fopen(filename, "w");
            fwrite(buffer, 1, 512, photo);
            break;
        }
    }

    while (fread(buffer, 1, 512, card) == 512)
    {
        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[3] >= 0xe0 && buffer[3] <= 0xef))
        {
            i++;
            fclose(photo);
            sprintf(filename, "%03d.jpg", i);
            photo = fopen(filename, "w");
            fwrite(buffer, 1, 512, photo);
            continue;
        }
        fwrite(buffer, 1, 512, photo);
    }

    fclose(photo);
    fclose(card);
}
