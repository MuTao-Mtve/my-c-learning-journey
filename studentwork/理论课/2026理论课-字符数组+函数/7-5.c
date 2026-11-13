#include <stdio.h>
#include <string.h>
int main(void)
{
    int n,count=0;
    char str1[81]={'\0'},str2[81]={'\0'};
    scanf("%d",&n);
    getchar();
    fgets(str1,sizeof(str1),stdin);
    count++;
    strncpy(str2,str1,sizeof(str2));
    for(int i=0;i<n;i++)
    {
        if(strlen(str1)>strlen(str2)) strncpy(str2,str1,sizeof(str2));
        if(count<n)
        {
            fgets(str1,sizeof(str1),stdin);
            count++;
        }
    }
    printf("The longest is: %s",str2);
    return 0;
}