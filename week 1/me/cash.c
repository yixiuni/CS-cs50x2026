#include <stdio.h>
#include <cs50.h>
int main (void)
{
    int co;
    do
    {
    co = get_int("Change owed: ");
    } while (co <= 0);
    int count =0 ;
    count += (co/25);
    co = (co%25);  //同理可简写co%=25
    count += (co/10);
    co =(co%10);
    count += (co/5);
    co = (co%5);
    count +=(co/1);
    printf("%d\n",count);
}

//better 循环
//int denominations[] = {25, 10, 5, 1};
// int count = 0;

// for (int i = 0; i < 4; i++)
// {
//     count += cents / denominations[i];
//     cents %= denominations[i];
// }

// printf("%d\n", count);
