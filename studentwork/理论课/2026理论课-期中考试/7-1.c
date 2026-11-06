#include <stdio.h>
int main(void)
{
    double a,b;
    char c;
    scanf("%lf%c%lf",&a,&c,&b);
    if(c == '+') printf("%.2lf",a+b);
    else if(c == '-') printf("%.2lf",a-b);
    else if(c == '*') printf("%.2lf",a*b);
    else if(c == '/')
    {
        if(b == 0) printf("Divisor can not be 0!");
        else printf("%.2lf",a/b);
    }
    else printf("Unknown operator!");
    return 0;
}