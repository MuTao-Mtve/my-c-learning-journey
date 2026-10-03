#include <stdio.h>
//
int main()
{
	char a,b,c;
	scanf( "%c%c%c",&a,&b,&c);
	if(c!='0')
	{
		printf("%c%c%c",c,b,a);
	}
	else if(b!='0')
	{
		printf("%c%c",b,a);
	}
	else
	{
		printf("%c",a);
	}
	return(0);
}