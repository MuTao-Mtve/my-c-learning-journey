#include <stdio.h>

int main(void)
{
    char str[80]={'\0'},hash[256]={'\0'};
    fgets(str,sizeof(str),stdin);
    for(int i=0;i<80;i++)
    {
        if(str[i]=='\n') break;
        if(hash[str[i]]==0) hash[str[i]]=str[i];
    }
    for(int i=0;i<256;i++)
    {
        if(hash[i]!='\0') putchar(hash[i]);
    }
    return 0;
}