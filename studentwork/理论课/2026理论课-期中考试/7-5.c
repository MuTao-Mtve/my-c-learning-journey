#include <stdio.h>
int main(void)
{
    int a,b,c,n,count=0;//a 5元一只 公鸡,b 3-1 muji,c 1-3 xiaoji
    scanf("%d",&n);
    for(a=1;a<=20;a++)
    {
        for(b=1;b<=33;b++)
        {
            c=(100-5*a-3*b)*3;
            if(a+b+c==100 && c>0)
            {
                printf("%d %d %d\n",a,b,c);
                count++;
                if(count==n) return 0;
            }
        }
    }
    return 0;
}