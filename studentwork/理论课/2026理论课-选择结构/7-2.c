#include <stdio.h>
int main(void)
{
    double x=0.0;
    scanf("%lf",&x);
    if(x!=10)
    {
        printf("f(%.1lf) = %.1lf",x,x);
    }
    else if (x==10)
    {
        printf("f(10.0) = 0.1");
    }
    return(0);
}