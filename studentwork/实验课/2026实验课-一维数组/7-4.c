#include <stdio.h>
int main(void)
{
    int n,x,tag=0;
    scanf("%d %d",&n,&x);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    for(int i=0;i<n;i++)
    {
        if(arr[i]==x)
        {
            printf("%d",i);
            tag=1;
            continue;
        }
        else if(i==n-1 && tag==0)
        {
            printf("Not Found");
        }
    }   
    return 0;
}