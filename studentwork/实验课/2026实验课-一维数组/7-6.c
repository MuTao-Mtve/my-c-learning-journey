#include <stdio.h>
#include <stdlib.h>
int compar(const void *a,const void *b)
{
    int x=*(const int *)a,y=*(const int *)b;
    return y-x;
}
void array_input(int arr[],int n)
{
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
}
int main(void)
{
    int m,n;
    scanf("%d",&m);
    int am[m];
    array_input(am,m);
    scanf("%d",&n);
    int an[n];
    array_input(an,n);
    int c[m+n];
    for(int i=0;i<m;i++) c[i]=am[i];
    for(int i=0;i<n;i++) c[i+m]=an[i];
    qsort(c,m+n,sizeof(int),compar);
    for(int i=0;i<m+n;i++) printf("%d ",c[i]);
    return 0;
}