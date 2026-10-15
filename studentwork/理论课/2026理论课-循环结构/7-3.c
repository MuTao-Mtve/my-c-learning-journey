#include <stdio.h>

int main(void)
{
    long int sum=0,i,n;
    scanf("%ld",&n);
    for(i=1;i<=n*n;i++) sum+=i;
    for(int i=1;i<=n;i++) sum+=i;
    printf("%ld",sum);
    return 0;
}