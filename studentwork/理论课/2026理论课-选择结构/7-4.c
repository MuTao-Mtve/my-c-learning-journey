#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(void)
{
    int a=0,b=0,c=0,d=0;
    scanf("%d",&a);
    if(a>=100&&a<=999)
    {
        b = a / 100;         
        c = (a / 10) % 10;    
        d = a % 10;
        if(a == b*b*b + c*c*c + d*d*d)
        {
            printf("Yes");
        }
        else
        {
            printf("No");
        }
    }
    else
    {
        printf("Invalid Value.");
    }

    return (0);
}