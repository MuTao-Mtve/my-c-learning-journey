#include <stdio.h>
int main(void)
{
    long int input=0;
    long int sum=0,i=0;
    scanf("%ld",&input);
    while(input>0)
    {
        sum=sum+input%10;
        i++;
        input=input/10;
    }
    printf("%ld %ld",i,sum);
    return 0;
}