#include <stdio.h>
#include <string.h>
void end(char arr[])
{
    arr[strcspn(arr,"\n")]='\0';
}
int main(void)
{
    int n,count=0;
    char arr1[81]={'\0'},arr2[81]={'\0'};
    scanf("%d",&n);
    getchar();
    fgets(arr1,sizeof arr1,stdin);
    end(arr1);
    count++;
    strncpy(arr2,arr1,sizeof arr1);
    for(int i=0;i<n;i++)
    {
        if(strncmp(arr1,arr2,sizeof arr1)<0) strncpy(arr2,arr1,sizeof arr2);
        if(count<n)
        {
            fgets(arr1,sizeof arr1,stdin);
            end(arr1);
            count++;
        }
    }
    printf("Min is: %s",arr2);
    return 0;
}