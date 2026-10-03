#include <stdio.h>
int main(void)
{
	int a=0,b=0,c=0;
	char f='+' ;
	scanf("%d %c %d",&a,&f,&b);
	if(f=='+') c=a+b;
	else if(f=='-') c=a-b;
	else if(f=='*') c=a*b;
	else if(f=='/') c=a/b;
	else if(f=='%') c=a%b;
	if(f=='+'||f=='-'||f=='*'||f=='/'||f=='%')
	{
		printf("%d",c);
	}
	else
	{
		printf("ERROR");
	}
	
	return(0);
}