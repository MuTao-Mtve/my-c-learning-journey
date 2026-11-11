#include <stdio.h>
long long int jiecheng(int n)
{
    long long int value=1;
    for(int i=1;i<=n;i++) value*=i;
    return value;
}
long long int zuheshu(int i,int j)
{
    long long int value=0;
    value=jiecheng(i)/(jiecheng(i-j)*jiecheng(j));
    return value;
}
int main(void)
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int k=0;k!=n-i-1;k++) printf(" ");
        for(int j=0;j<=i;j++)
        {
            printf("%4lld",zuheshu(i,j));
            if(j==i) printf("\n");
        }
    }
    return 0;
}