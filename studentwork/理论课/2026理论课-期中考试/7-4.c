#include <stdio.h>
int main(void)
{
    double n,PI=0;
    scanf("%lf",&n);
    if(n!=(int)n || n<=0) 
    {
        printf("项数必须为正整数。");
        return 0;
    }
    for(int i=1,j=1;i<=n;i++,j+=2)
    {
        if(i%2!=0) PI+=1.0/j;
        else PI-=1.0/j;
    }
    PI*=4;
    printf("%.5lf",PI);
    return 0;
}