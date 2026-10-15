#include <stdio.h>
int main(void)
{
    int tag=0,i=1;
    char ch;
    for(ch=getchar();ch!='\n'&&ch!=EOF;ch=getchar())
    {
        if(i==1&&ch>='a'&&ch<='z') ch=ch-32;
        if(tag==1&&ch>='a'&&ch<='z') 
        {
            ch=ch-32;
            tag=0;
        }
        else
        {
            tag=0;
        }
        if(ch==' ') tag=1;
        printf("%c",ch);
        i++;
    }
    return 0;
}