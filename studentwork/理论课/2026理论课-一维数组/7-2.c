#include <stdio.h>
int main(void)
{
    int n,location_max,temp;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n-1;i++)
    {
        if((i+1)%3==0 || i==n-2) printf("%d\n",a[i+1]-a[i]);
        else printf("%d ",a[i+1]-a[i]);
    }
    return 0;
}