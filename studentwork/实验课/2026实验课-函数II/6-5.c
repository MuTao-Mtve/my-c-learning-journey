#include <stdio.h>
#define MAXN 10

void ArrayShift( int a[], int n, int m );

int main()
{
    int a[MAXN], n, m;
    int i;
    
    scanf("%d %d", &n, &m);
    for ( i = 0; i < n; i++ ) scanf("%d", &a[i]);
    
    ArrayShift(a, n, m);
    
    for ( i = 0; i < n; i++ ) {
        if (i != 0) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
    
    return 0;
}

void ArrayShift( int a[], int n, int m )
{
    for(int i=0;i<m;i++)
    {
        int temp=a[n-1];
        for(int j=n-1;j>=1;j--) a[j]=a[j-1];
        a[0]=temp;
    }
}