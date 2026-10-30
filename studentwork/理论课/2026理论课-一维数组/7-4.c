#include <stdio.h>
#include <stdlib.h>
int compar(const void *a,const void *b)
{
    int x=*(const int *)a,y=*(const int *)b;
    return x-y;
}
int main(void)
{
    int n;
    scanf("%d",&n);
    int arr[n+1];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    scanf("%d",&arr[n]);
    qsort(arr,n+1,sizeof(int),compar);
    for(int i=0;i<n+1;i++) printf("%d ",arr[i]);
    return 0;
}