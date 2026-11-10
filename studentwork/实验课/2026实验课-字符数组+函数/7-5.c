#include <stdio.h>
int main(void)
{
    char ch,arr[81]={'\0'};
    scanf("%c",&ch);
    getchar();
    fgets(arr,sizeof arr,stdin);
    for(int i=80;i>=0;i--)
    {
        if(arr[i]==ch)
        {
            printf("index = %d",i);
            return 0;
        }
    }
    printf("Not Found");
    return 0;
}