#include <stdio.h>
int main()
{
	int a=0,b=0,c=0,d=0,Sum=0;
	double Average=0;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	Sum=(a+b+c+d);
	Average=(double)Sum/4;
	printf("Sum = %d; Average = %.1lf",Sum,Average);
	return(0);
}