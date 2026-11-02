#include <stdio.h>
#include <cs50.h>

int main (void)
{
    long number;
    int len = 0;
    int arr[20];
    int sum=0;

    do
    {
    number= get_long("Number: ");
    } while(number <= 0) ;
    while (number > 0)
    {
        arr[len] =number % 10;
        number /= 10;
        len ++;
    }


    for(int j=0;j<len;j++)
      {
        if (j%2 !=0)
        {
           int count =arr[j] *2;
           sum += ((count / 10) + (count % 10));
        }

        else
        {
            sum += arr[j];
        }
      }

    if (sum%10 != 0)
    {
        printf("INVALID\n");
    }
    else if(len==15 && (arr[len-1]==3) && (arr[len-2]==4 || arr[len-2]==7))
    {
        printf("AMEX\n");
    }
    else if(arr[len-1]==4 && (len==13 || len ==16 ))
    {
        printf("VISA\n");
    }
    else if(len==16 && arr[len-1]==5 && (arr[len-2]>=1 && arr[len-2]<=5))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
