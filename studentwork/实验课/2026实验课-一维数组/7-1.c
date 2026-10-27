#include <stdio.h>
int main(void)
{
    int n,location_max=0;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    for(int i=0;i<n;i++) location_max=arr[location_max]>=arr[i]?location_max:i;
    printf("%d %d",arr[location_max],location_max);
    return 0;
}