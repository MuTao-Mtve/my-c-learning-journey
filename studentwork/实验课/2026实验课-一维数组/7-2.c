#include <stdio.h>
int main(void)
{
    int n,location_max,temp;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    for(int i=0;i<n;i++)
    {
        location_max=i;
        for(int j=i;j<n;j++)
        {
            location_max=arr[location_max]>arr[j]?location_max:j;
        }
        if(location_max!=i)
        {
            temp=arr[location_max];
            arr[location_max]=arr[i];
            arr[i]=temp;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(i!=n-1) printf("%d ",arr[i]);
        else printf("%d",arr[i]);
    }
    return 0;
}