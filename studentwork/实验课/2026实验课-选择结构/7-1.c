#include <stdio.h>
int main(void)
{
	int grade=0;
	scanf("%d",&grade);
	if(grade>=90)
	{
		printf("gong xi ni kao le %d fen!",grade);
	}
	else
	{
		printf("kao le %d fen bie xie qi!",grade);
	}
	return(0);
}