#include <stdio.h>
int main(void)
{
    int n,A=0,B=0,C=0,D=0,E=0;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf(" %d",&a[i]);
    for(int i=0;i<n;i++)
    {
        if(a[i]>=90) A++;
        else if(a[i]>=80) B++;
        else if(a[i]>=70) C++;
        else if(a[i]>=60) D++;
        else E++;
    }
    printf("%d %d %d %d %d",A,B,C,D,E);
    return 0;
}