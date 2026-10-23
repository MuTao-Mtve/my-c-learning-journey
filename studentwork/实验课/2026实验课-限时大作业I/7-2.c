#include <stdio.h>
int main(void)
{
    int a;
    scanf("%d",&a);
    if(a>=90) printf("gong xi ni kao le %d fen!",a);
    else if(a<90) printf("kao le %d fen bie xie qi!",a);
    return 0;
}