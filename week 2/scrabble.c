#include <cs50.h>
#include <stdio.h>
#include <string.h>

int check(string n);
int main(void)
{
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    int count1 = check(word1);
    int count2 = check(word2);

    if (count1 > count2)
    {
        printf("Player 1 wins!\n");
    }
    else if (count1 < count2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// int check (string n)
// {
//     int len = strlen(n);
//     int count=0;
//     for (int i = 0;i < len;i++)
//     {
//         if (n[i] == 'A' || n[i]=='a')
//         {
//            count += 1;
//         }
//         else if (n[i] == 'B' || n[i]=='b')
//         {
//            count += 3;
//         }
//         else if (n[i] == 'C' || n[i]=='c')
//         {
//            count += 3;
//         }
//         else if (n[i] == 'D' || n[i]=='d')
//         {
//            count += 2;
//         }
//         else if (n[i] == 'E' || n[i]=='e')
//         {
//             count += 1;
//         }
//         else if (n[i] == 'F' || n[i]=='f')
//         {
//             count += 4;
//         }
//         else if (n[i] == 'G' || n[i]=='g')
//         {
//             count += 2;
//         }
//         else if (n[i] == 'H' || n[i]=='h')
//         {
//             count += 4;
//         }
//         else if (n[i] == 'I' || n[i]=='i')
//         {
//             count += 1;
//         }
//         else if (n[i] == 'J' || n[i]=='j')
//         {
//             count += 8;
//         }
//         else if (n[i] == 'K' || n[i]=='k')
//         {
//             count += 5;
//         }
//         else if (n[i] == 'L' || n[i]=='l')
//         {
//             count += 1;
//         }
//         else if (n[i] == 'M' || n[i]=='m')
//         {
//             count += 3;
//         }
//         else if (n[i] == 'N' || n[i]=='n')
//         {
//             count += 1;
//         }
//         else if (n[i] == 'O' || n[i]=='o')
//         {
//             count += 1;
//         }
//         else if (n[i] == 'P' || n[i]=='p')
//         {
//             count += 3;
//         }
//         else if (n[i] == 'Q' || n[i]=='q')
//         {
//             count += 10;
//         }
//         else if (n[i] == 'R' || n[i]=='r')
//         {
//             count += 1;
//         }
//         else if (n[i] == 'S' || n[i]=='s')
//         {
//             count += 1;
//         }
//         else if (n[i] == 'T' || n[i]=='t')
//         {
//             count += 1;
//         }
//         else if (n[i] == 'U' || n[i]=='u')
//         {
//             count += 1;
//         }
//         else if (n[i] == 'V' || n[i]=='v')
//         {
//             count += 4;
//         }
//         else if (n[i] == 'W' || n[i]=='w')
//         {
//             count += 4;
//         }
//         else if (n[i] == 'X' || n[i]=='x')
//         {
//             count += 8;
//         }
//         else if (n[i] == 'Y' || n[i]=='y')
//         {
//             count += 4;
//         }
//         else if (n[i] == 'Z' || n[i]=='z')
//         {
//             count += 10;
//         }
//     }

//     return count;

// }

// 函数改进
int check(string n)
{
    int len = strlen(n);
    int count = 0;
    int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    for (int i = 0; i < len; i++)
    {
        if (n[i] >= 'A' && n[i] <= 'Z')
        {
            count += points[n[i] - 'A'];  //有点意思
        }
        else if (n[i] >= 'a' && n[i] <= 'z')
        {
            count += points[n[i] - 'a'];
        }
    }
    return count;
}
