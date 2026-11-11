#include <stdio.h>
int main(void)
{
    int n,sum=0;
    scanf("%d",&n);
    int a[n][n];
    int *p=&a[0][0];
    for(int i=0;i<n*n;i++)
    {
        scanf("%d",p);
        p++;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            sum+=a[i][j];
        }
    }
    printf("%d",sum);
    return 0;
}