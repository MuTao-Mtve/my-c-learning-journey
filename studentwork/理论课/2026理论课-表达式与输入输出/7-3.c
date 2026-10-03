#include <stdio.h>


int main(void)
{
	int a,b,a1,a2,a3;
	double a4;
	scanf("%d %d",&a,&b);
	a1=a+b;
	a2=a-b;
	a3=a*b;
	a4=(double)a/(double)b;
	printf("%d + %d = %d\n",a,b,a1);
	printf("%d - %d = %d\n",a,b,a2);
	printf("%d * %d = %d\n",a,b,a3);
	if((int)a4!=a4)
	{
		printf("%d / %d = %.2lf",a,b,a4);
	}
	else
	{
		printf("%d / %d = %d",a,b,(int)a4);
	}
}