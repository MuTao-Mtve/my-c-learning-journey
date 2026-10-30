#include <stdio.h>
int main(void)
{
    int n,lmax=0,lmin=0,temp_max,temp_min;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    for(int i=0;i<n;i++)
    {
        if(arr[i]>arr[lmax]) lmax=i;
    }
    temp_max=arr[lmax];
    arr[lmax]=arr[n-1];
    arr[n-1]=temp_max;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<arr[lmin]) lmin=i;
    }
    temp_min=arr[lmin];
    arr[lmin]=arr[0];
    arr[0]=temp_min;
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    return 0;
}