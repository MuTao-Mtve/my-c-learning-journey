#include <stdio.h>
int main(void)
{
    int n,m,temp;
    scanf("%d %d",&n,&m);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    for(int i=0;i<m;i++)
    {
        temp=arr[n-1];
        for(int j=n-1;j>0;j--)
        {
            arr[j]=arr[j-1];  
        }
        arr[0]=temp;
    }
    for(int i=0;i<n;i++)
    {
        if(i!=n-1) printf("%d ",arr[i]);
        else printf("%d",arr[i]);
    }
    return 0;
}