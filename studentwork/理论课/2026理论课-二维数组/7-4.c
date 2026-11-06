#include <stdio.h>
#include <stdlib.h>
int compar(const void *a,const void *b)
{
    int x=*(const int *)a,y=*(const int *)b;
    return x-y;
}
int main(void)
{
    int arr[4][5],temp_arr[4];
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<5;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=0;i<5;i++) 
    {
        for(int j=0;j<4;j++) temp_arr[j]=arr[j][i]; 
        qsort(temp_arr,4,sizeof(int),compar);
        for(int j=0;j<4;j++) arr[j][i]=temp_arr[j];
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<5;j++) printf("%4d",arr[i][j]);
        printf("\n");
    }
    return 0;
}