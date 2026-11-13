#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[82]={'\0'};
    fgets(str,sizeof(str),stdin);
    str[strlen(str)-1]='\0';
    for(int i=strlen(str)-1;i>=0;i--) putchar(str[i]);
    return 0;
}