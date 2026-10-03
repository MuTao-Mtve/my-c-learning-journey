#include <stdio.h>


int main(void)
{
	double a,d;
	int b;
	char c;
	scanf("%lf %d %c %lf",&a,&b,&c,&d);
	printf("%c %d %.2lf %.2lf",c,b,a,d);
	return(0);
}