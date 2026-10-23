#include <stdio.h>
int main(void)
{
    double sum=0;
    int N,k=1;
    scanf("%d",&N); 
    for(double i=1,j=1.0;i<=N;i++,j+=2.0)
    {
        if(k%2!=0) sum+=i/j;
        else sum-=i/j;
        k++;
    }
    printf("%.3lf",sum);
    return 0;
}