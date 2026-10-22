#include <stdio.h>
int main(void)
{
    char ch;
    int blank=0,digit=0,other=0;
    for(ch=getchar();ch!='\n'&&ch!=EOF;ch=getchar())
    {
        if(ch==' ') blank++;
        else if(ch>='0'&&ch<='9') digit++;
        else other++;
    }
    printf("blank = %d, digit = %d, other = %d",blank,digit,other);
    return 0;
}