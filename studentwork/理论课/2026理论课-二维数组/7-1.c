#include <stdio.h>
int main(){
    int n,max=0;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    for(int i=0;i<n;i++)
    {
        if(arr[max]<arr[i]) max=i;
    }
    printf("%d %d",arr[max],max);
    return 0;
}