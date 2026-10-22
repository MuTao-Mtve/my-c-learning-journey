#include <stdio.h>
int sushu(int a)
{
    if(a<=1) return 0;
    for(int i=2;i<a;i++)
    {
        if(a%i == 0) return 0;
    }
    return 1;
}
int main(void)
{
    int M,N,count=0,sum=0;
    scanf("%d %d",&M,&N);
    for(int i=M;i>=M&&i<=N;i++)
    {
        if(sushu(i))
        {
            count++;
            sum+=i;
        }
    }
    printf("%d %d",count,sum);
    return 0;
}