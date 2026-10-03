#include <stdio.h>


int main(void)
{
	double a,b,c,average,sum;
	scanf("%lf %lf %lf",&a,&b,&c);
	sum=a+b+c;
	average=sum/3.0;
	printf("sum = %.2lf; average = %.2lf",sum,average);
	return(0);
	
}