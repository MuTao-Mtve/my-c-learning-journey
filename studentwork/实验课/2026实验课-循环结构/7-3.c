#include <stdio.h>
double jiecheng(int n) //注意int返回类型的阶乘结构可能存在int溢出的问题
{
    double a=1;
    for(int i=1;i<=n;i++)
    {
        a=a*i;
    }
    return(a);
}
int main(void)
{
    int n=0;
    double e=0.0;
    scanf("%d",&n);
    for(int i=0;i<=n;i++)
    {
        e=e+(1/jiecheng(i));
    }
    printf("%.8lf",e);
    return 0;
}