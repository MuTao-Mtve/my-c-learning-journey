#include <stdio.h>
#define LETTER_CHANGE ('a'-'A')
int main(void)
{
    char str[31];
    fgets(str,sizeof(str),stdin);
    for(int i=30;i>=0;i--)
    {
        if(str[i]=='#')
        { 
            str[i]='\0';
            break;
        }
    }
    for(int i=0;i<31;i++)
    {
        if(str[i]>='A' && str[i]<='Z') str[i]+=LETTER_CHANGE;
        else if(str[i]>='a' && str[i]<='z') str[i]-=LETTER_CHANGE;
    }
    printf("%s",str);
    return 0;
}