#include <stdio.h>
int main(void)
{
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    int key,tag=0;
    scanf("%d",&key);
    for(int i=0;i<10;i++)
    {
        if(arr[i]==key)
        {
            printf("weizhi:%d",i);
            tag=1;
        }
    }
    if(tag==0) printf("not found");
    return 0;
}