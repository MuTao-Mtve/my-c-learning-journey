#include <stdio.h>
#define MAXN 10

void sort( int a[], int n );

int main()
{
    int i, n;
    int a[MAXN];
    
    scanf("%d", &n);
    for( i=0; i<n; i++ )
        scanf("%d", &a[i]);

    sort(a, n);

    printf("After sorted the array is:");
    for( i = 0; i < n; i++ )
        printf(" %d", a[i]);
    printf("\n");
        
    return 0;
}
#include <stdlib.h>
int compar(const void *a,const void *b)
{
    int x=*(const int *)a;
    int y=*(const int *)b;
    return x-y;
}
void sort( int a[], int n )
{
    qsort(a,n,sizeof(int),compar);
}
