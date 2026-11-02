#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    int letter;
    int word;
    int sentence;
} Count;

Count get_number(string n);

int main (void)
{
    string text = get_string("Text: ");
    Count count = get_number(text);
    double L=(double)count.letter/count.word*100;  // 数据是int  计算是“/”所以转换（double）
    double S=(double)count.sentence/count.word*100;
    int index = (int)round(0.0588 * L - 0.296 * S - 15.8); //round--四舍五入，返回double类型 （int）转换
    if (index >=1 && index <16)
    {
    printf("Grade %i\n",index);
    }
    else if(index >=16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }


}



Count get_number(string n)
{
    Count count;
     count.letter = 0;
     count.word = 1;
     count.sentence = 0;
    int len =strlen(n);
    for (int i = 0;i < len;i++)
    {
        if((n[i] >= 'a' && n[i] <= 'z')||(n[i] >= 'A' && n[i] <='Z'))
        {
            count.letter ++;
        }
        else if (n[i]==' ')
        {
            count.word ++;
        }
        else if ((n[i]=='!')||(n[i]=='?')||(n[i]=='.'))
        {
            count.sentence ++;
        }
    }
    return count;
}

