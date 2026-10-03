#include <stdio.h>
int main(void)
{
    int a[3]={0,0,0};
    int temp=0;

    scanf("%d %d %d",&a[0],&a[1],&a[2]);
    while (!(a[0]<=a[1] && a[1]<=a[2]))
    {
        if(a[0]>a[1])
        {
            temp=a[0];
            a[0]=a[1];
            a[1]=temp;
        }
        else if (a[1]>a[2])
        {
            temp=a[1];
            a[1]=a[2];
            a[2]=temp;
        }
    }
    printf("%d->%d->%d",a[0],a[1],a[2]);
    return(0);
}