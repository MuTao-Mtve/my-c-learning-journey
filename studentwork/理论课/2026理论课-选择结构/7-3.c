#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(void)
{
    double a=0,b=0,c=0,perimeter=0;
    double s=0.0,area=0.0;
    scanf("%lf %lf %lf",&a,&b,&c);
    if(a+b>c&&a+c>b&&b+c>a)
    {
        s=(a+b+c)/2.0;
        area=sqrt(s*(s-a)*(s-b)*(s-c));
        perimeter=a+b+c;
        printf("area = %.2lf; perimeter = %.2lf",area,perimeter);
    }
    else
    {
        printf("These sides do not correspond to a valid triangle");
    }

    return (0);
}