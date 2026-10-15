#include <stdio.h>
int main(void)
{
    int m,n; 
    scanf("%d",&m);
    n=m/2+1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j!=(n-i)*2;j++) printf(" ");
        for(int j=0;j!=2*i-1;j++) printf("* ");
        printf("\n");
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j!=i*2;j++) printf(" ");
        for(int j=0;j!=m-i*2;j++) printf("* ");
        printf("\n");
    }
    return 0;
    
}