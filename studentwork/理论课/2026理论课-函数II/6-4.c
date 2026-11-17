#include <stdio.h>

int reverse( int number );
    
int main()
{
    int n;

    scanf("%d", &n);
    printf("%d\n", reverse(n));

    return 0;
}

int reverse( int number )
{
    int value=0;
    for(;number!=0;number/=10) value=value*10+number%10;
    return value;
}
