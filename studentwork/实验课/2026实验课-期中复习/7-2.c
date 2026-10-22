#include <stdio.h>
int main(void)
{
    double a,b;
    scanf("%lf %lf",&a,&b);
    a=a*b*0.1;
    printf("%.2lf",a);
    return 0;  
}