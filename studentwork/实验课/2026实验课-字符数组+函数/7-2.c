#include <stdio.h>
int main(void)
{
    int sum=0;
    char arr[101]={'\0'};
    fgets(arr,sizeof arr,stdin);
    for(int i=0;i<101;i++)
    {
        if(arr[i]>='0' && arr[i]<='9') sum+=(arr[i]-'0');
    }
    printf("sum=%d",sum);
    return 0;
}