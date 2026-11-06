#include <stdio.h>
int main(void)
{
    int m,n;
    scanf("%d %d",&n,&m);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    for(int i=0;i<m;i++)
    {
        int temp=arr[0];
        for(int j=0;j<n-1;j++)
        {
            arr[j]=arr[j+1];
        }
        arr[n-1]=temp;
    }
    for(int i=0;i<n-1;i++) printf("%d ",arr[i]);
    printf("%d",arr[n-1]);
    return 0;
}