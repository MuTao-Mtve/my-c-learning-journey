#include <stdio.h>
int main(void)
{
    int n,k,temp;
    scanf("%d %d",&n,&k);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
        if(i==k-1) break;
    }
    for(int i=0;i<n-1;i++) printf("%d ",arr[i]);
    printf("%d",arr[n-1]);
    return 0;
}