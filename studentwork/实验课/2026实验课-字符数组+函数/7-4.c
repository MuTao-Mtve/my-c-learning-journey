#include <stdio.h>
int main(void)
{
    int tag=1,count=0;
    char ch;
    for(ch=getchar();ch!='\n' && ch!=EOF;ch=getchar())
    {
        if(ch!=' ')
        {
            if(tag==1)
            {
                count++;
                tag=0;
            }
        }
        if(ch==' ') tag=1;
    }
    printf("%d",count);
    return 0;
}