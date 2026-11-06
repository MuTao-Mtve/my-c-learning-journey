#include <stdio.h>
int main(void)
{
    int a,temp,sum=0;
    scanf("%d",&a);
    for(;a>=10;a=a/10)
    {
        temp=a%10;
        sum+=temp;
    }
    printf("%d",sum+a);
    return 0;
}