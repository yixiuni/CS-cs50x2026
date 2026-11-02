#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = get_int("Height: ");

    int line = 0;
    while (!(height > 0))  //直接<=
    {
        height = get_int("Height: ");
    }
    // 6，11行重复，do while更好

    for (int i = 1; i <= height; i++)
    {
        line = i;
        for (int j = 0; j < height - i; j++)
        {
            printf(" ");
        }
        while (line > 0)
        {
            printf("#");
            line--;
        }
        // for (int brick = 0; brick < i; brick ++) 更好
        printf("\n");
    }
}
