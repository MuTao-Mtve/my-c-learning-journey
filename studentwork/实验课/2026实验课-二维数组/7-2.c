#include <stdio.h>
#include <math.h>
int main(void)
{
    int m,n;
    scanf("%d %d",&m,&n);
    int a[m][n],sum[n];
    int *p=&a[0][0];
    for(int i=0;i<n*m;i++)
    {
        scanf("%d",p);
        p++;
    }
    for(int i=0;i<n;i++) sum[i]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(abs(a[j][i])%2!=0) sum[i]+=a[j][i];
        }
    }
    for(int i=0;i<n;i++) printf("%d ",sum[i]);
    return 0;
}