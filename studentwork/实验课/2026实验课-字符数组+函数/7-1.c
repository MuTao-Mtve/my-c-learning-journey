#include <stdio.h>
int main()
{
    char arr[81],ch;
    int count=0;
    fgets(arr,sizeof arr,stdin);
    scanf("%c",&ch);
    for(int i=0;i<81;i++)
    {
        if(arr[i]==ch) count++;
    }
    printf("%d",count);
    return 0;
}