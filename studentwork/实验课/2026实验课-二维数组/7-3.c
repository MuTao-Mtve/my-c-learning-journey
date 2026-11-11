#include <stdio.h>
int main(void)
{
    int m,n;
    scanf("%d %d",&m,&n);
    int a[m][n];
    int *p=&a[0][0];
    for(int i=0;i<m*n;i++)
    {
        scanf("%d",p);
        p++;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(j!=m-1) printf("%d ",a[j][i]);
            else printf("%d\n",a[j][i]);
        }
    }
    return 0;
}