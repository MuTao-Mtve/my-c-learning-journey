#include <stdio.h>
int main(void)
{
	double ele_used=0.0,cost=0.0;
	scanf("%lf",&ele_used);
	if(ele_used<=50&&ele_used>=0)
	{
		cost=ele_used*0.53;
		printf("cost = %.2lf",cost);
	}
	else if(ele_used>50)
	{
		cost=50*0.53+(ele_used-50)*0.58;
		printf("cost = %.2lf",cost);
	}
	else
	{
		printf("Invalid Value!");
	}
	return(0);
}