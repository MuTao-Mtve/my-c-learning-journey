#include <stdio.h>
double jiecheng(int n)
{
    double value=1;
    for(int i=1;i<=n&&n!=0;i++) value=value*i;
    return (double)value;
}
double fengmu(int n)
{
    double value=1;
    for(int i=1;i<=2*n+1&&n!=0;i=i+2) value=value*i;
    return (double)value;
}
int main(void)
{
    double eps,last_value=0.0,PI=0.0;
    int i=0;
    scanf("%le", &eps);
    do
    {
        last_value=jiecheng(i)/fengmu(i);
        PI+=last_value;
        i++;
    } while (last_value>eps);
    PI=PI*2;
    printf("PI = %.5lf",PI);
    return 0;
}