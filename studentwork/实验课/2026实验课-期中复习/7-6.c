#include <stdio.h>
int sxh(int i)
{
    int a,b,c;
    a=i/100;
    b=i/10-a*10;
    c=i%10;
    if(a*a*a+b*b*b+c*c*c==i) return 1;
    else return 0;
}
int main(void)
{
    int m,n;
    scanf("%d %d",&m,&n);
    if(!(100<=m && m<=n && n<=999)) 
    {
        printf("Invalid Value.");
        return 0;
    }
    for(int i=m;i<=n;i++)
    {
        if(sxh(i)) 
        {
            printf("%d\n",i);
        }
    }
    return 0;
}