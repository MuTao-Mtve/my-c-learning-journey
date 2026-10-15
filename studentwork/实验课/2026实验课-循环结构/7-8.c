#include <stdio.h>
int main(void)
{
    int a=1,b=1,c,i=0,n;
    scanf("%d",&n);
    while(a<100)
    {
        for(a=1;a<=100;a++)
        {
            for(b=1;b<=100;b++)
            {
                c=100-a-b;
                if(a*5+b*2+c==150&&a+b+c==100)
                {
                    printf("%d %d %d\n",a,b,c);
                    i++;
                    if(i==n) return 0;
                }
            }
        }
    }
    return 0;
}