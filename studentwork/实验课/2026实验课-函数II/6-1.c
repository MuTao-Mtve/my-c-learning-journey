#include <stdio.h>

void dectobin( int n );

int main()
{
    int n;
    
    scanf("%d", &n);
    dectobin(n);
    
    return 0;
}
// Ñ­»·Ëã·¨
void dectobin( int n )
{
    if(n==0)
    {
        printf("%d",n);
        return;
    }
    int arr[32]={0},i=0;
    while (n>1)
    {
        arr[i]=n%2;
        n/=2;
        i++;
    }
    if(n==1) printf("%d",n);
    for(int j=i-1;j>=0;j--) printf("%d",arr[j]);
}
/*µÝ¹éËã·¨
void dectobin( int n )
{
    if(n>1) dectobin(n/2);
    printf("%d",n%2);
}
*/