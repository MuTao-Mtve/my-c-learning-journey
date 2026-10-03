#include <stdio.h>
int main(void)
{
	double x=0.0,y=0.0;
	scanf("%lf",&x);
	if(x<=15)
	{
		y=(x*4)/3.0;
		printf("%.2lf",y);
	}
	else
	{
		y=2.5*x-17.5;
		printf("%.2lf",y);
	}
	return(0);
}