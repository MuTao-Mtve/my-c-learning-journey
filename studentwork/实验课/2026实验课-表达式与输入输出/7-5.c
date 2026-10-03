#include <stdio.h>
#include <math.h>

int main(void)
{
	double interest=0,rate=0,year=0,money=0;
	scanf("%lf %lf %lf",&money,&year,&rate);
	interest=money*pow((1+rate),year)-money;
	printf("interest = %.2lf",interest);
	return(0);
}