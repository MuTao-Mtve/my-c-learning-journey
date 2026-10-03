#include <stdio.h>


int main(void)
{
	char a1,a2;
	int b;
	scanf("%c",&a1);
	b=(int)a1;
	if(b>=65&&b<=90)
	{
		a2=a1+32;
		printf("%c",a2);
	}
	else
	{
		a2=a1-32;
		printf("%c",a2);
	}
	return(0);
}