#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int max_run=0,num_input=0,A1=-1,A2=0,A3_count=0,temp=0;
    double A3=0.0;
    scanf("%d",&max_run);
    for(int num_run=0;num_run<max_run;num_run++)
    {
        scanf("%d",&num_input);
        if(num_input%3==0)
        {
            temp=num_input;
            if(temp>=A1)
            {
                A1=num_input;
            }
        }
        for(int i=0;i<num_input;i++)
        {
            if((3*i+1)==num_input)
            A2++;
        }
        for(int i=0;i<num_input;i++)
        {
            if((3*i+2)==num_input)
            {
            A3=A3+num_input;
            A3_count++;
            }
        }
    }
    if(A3_count==0)
    {
        A3=0;
    }
    else
    {
        A3=A3/(double)A3_count;
    }

    
    if(A1!=-1)
    {
        printf("%d ",A1);
    }
    else
    {
        printf("NONE ");
    }
    if(A2!=0)
    {
        printf("%d ",A2);
    }
    else
    {
        printf("NONE ");
    }
    if(A3_count!=0)
    {
        printf("%.1lf",A3);
    }
    else
    {
        printf("NONE");
    }
    return(0);
}