#include <stdio.h>
int main(void)
{
    int m,n,mrow=0,mcol=0;
    scanf("%d %d",&m,&n);
    int arr[m][n];
    for(int j=0;j<m;j++)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[j][i]);
        } 
    }
    for(int j=0;j<m;j++)
    {
        for(int i=0;i<n;i++)
        {
            if(arr[mrow][mcol]>arr[j][i])
            {
                mrow=j;
                mcol=i;
            }
            printf("%4d",arr[j][i]);
        }
        printf("\n");
    }
    printf("min = a[%d][%d] = %d",mrow,mcol,arr[mrow][mcol]);
    return 0;
}