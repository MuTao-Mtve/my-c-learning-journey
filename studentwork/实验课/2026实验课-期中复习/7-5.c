#include <stdio.h>
int main(void)
{   
    double gas90=6.95,gas93=7.44,gas97=7.93;
    double value=0,pingzhong=0;
    double b,c,price;
    char ch;
    scanf("%lf %lf %c",&value,&pingzhong,&ch);
    if(pingzhong==90) b=gas90;
    else if(pingzhong==93) b=gas93;
    else if(pingzhong==97) b=gas97;
    if(ch=='m') c=0.95;
    else if(ch=='e') c=0.97;
    price=value*b*c;
    printf("%.2lf",price);
    return 0;
}