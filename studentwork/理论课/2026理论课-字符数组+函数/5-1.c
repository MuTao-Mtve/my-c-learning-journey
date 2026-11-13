#include <stdio.h>
#define MAX_LEN 100
int main()
{
    char inStr[MAX_LEN+1];
    char outStr[MAX_LEN+1];
     gets(inStr);
     int i = 0,j=0;
     while(inStr[i] != '\0'){
          if(inStr[i] != ' '){//不是空格，就留下来
                outStr[j] = inStr[i];
                j++;
          }
          i++;
     }
     outStr[j]='\0';
     printf("%s\n", outStr);
     return 0;
}