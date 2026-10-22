#include <stdio.h>
int main(void)
{
    int change=0,a,b,c,d=0;
    scanf("%d",&change);
    for(a=20;a>0;a--)
    {
        for(b=50;b>0;b--)
        {
            for(c=100;c>0;c--)
            {
                if(a*5+b*2+c==change)
                {
                    printf("fen5:%d, fen2:%d, fen1:%d, total:%d\n",a,b,c,a+b+c);
                    d++;
                }
            }
        }
    }
    printf("count = %d\n",d);
    return 0;
}