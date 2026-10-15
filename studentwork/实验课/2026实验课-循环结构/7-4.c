#include <stdio.h>
int main(void)
{
    int N=0,M=0;
    double Pi=0.0;
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;i++)
    {
        scanf("%lf",&Pi);
        if(Pi<M) printf("On Sale! %.1lf\n",Pi);
    }
    return 0;
}