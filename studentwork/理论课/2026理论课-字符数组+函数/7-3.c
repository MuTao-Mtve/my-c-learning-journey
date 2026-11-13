#include <stdio.h>
#define LENGTH ('A'+'Z')
int main(void)
{
    char str[81]={'\0'};
    fgets(str,sizeof(str),stdin);
    for(int i=0;i<80;i++)
    {
        if(str[i]>='A' && str[i]<='Z') str[i]=LENGTH-str[i];
        if(str[i]=='\n')
        {
            str[i]='\0';
            break;
        }
    }
    puts(str);
    return 0;
}