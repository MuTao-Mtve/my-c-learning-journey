#include <stdio.h>

int fib( int n );
void PrintFN( int m, int n );
    
int main()
{
    int m, n, t;

    scanf("%d %d %d", &m, &n, &t);
    printf("fib(%d) = %d\n", t, fib(t));
    PrintFN(m, n);

    return 0;
}
//循环算法
int fib( int n )
{
    int a1=1,a2=1;
    if(n<=2) return 1;
    int a3;
    for(int i=3;i<=n;i++)
    {
        a3=a1+a2;
        a1=a2;
        a2=a3;
    }
    return a3;
}
//递归算法 性能不如循环迭代法，不推荐
/*
int fib(int n)
{
    if(n<=2) return 1;
    int temp1,temp2;
    temp1=fib(n-1);
    temp2=fib(n-2);
    return (temp1+temp2);

}
*/
void PrintFN( int m, int n )
{
    int value,i=1,count=0;
    do
    {
        value=fib(i);
        if(value>=m && value<=n)
        {
            if(!(count)) printf("%d",value);
            else printf(" %d",value);
            count++;
        }
        i++;
    }while (value<=n && value>=0);
    if(!(count)) printf("No Fibonacci number");
}