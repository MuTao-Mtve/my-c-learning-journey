#include <stdio.h>
#include <math.h>
int main(void)
{
    double x,result;
    scanf("%lf",&x);
    if(x>=0) result=sqrt(x);
    else result=(pow((x+1),2)+2*x+1/x);
    printf("f(%.2lf) = %.2lf",x,result);
    return 0;
}