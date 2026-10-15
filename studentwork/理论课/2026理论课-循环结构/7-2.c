#include <stdio.h>
int main(void)
{
    int n;
    scanf("%d",&n);
    getchar();
    int letter=0,blank=0,digit=0,other=0;
    char temp='\0';
    for(int i=0;i<n;i++)
    {
        temp=getchar();
        if((temp>='a'&&temp<='z')||(temp>='A'&&temp<='Z')) letter++;
        else if(temp=='\n'||temp==' ') blank++;
        else if(temp>='0'&&temp<='9') digit++;
        else other++;
    }
    printf("letter = %d, blank = %d, digit = %d, other = %d",letter,blank,digit,other);
    return 0;
}