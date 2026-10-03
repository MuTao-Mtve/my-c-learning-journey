#include <stdio.h>

int main(void)
{
	double price_off=0,rate_off=0,price=0,a=0.1;
	scanf("%lf %lf",&price,&rate_off);
	rate_off=rate_off*a;
	price_off=price*rate_off;
	printf("%.2lf",price_off);
	return(0);
}