#include <stdio.h>
#include <stdlib.h>
void bubble_sort(int arr[], int n)
{
    int temp=0.0;
    for (int i=0;i<n-1;i++)
    {
        for (int j=0;j<n-i-1;j++)
        {
            if(arr[j] < arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int sushu(int n)
{
    for(int i=2;i<n;i++)
    {
        if(n%i==0) return 0;
    }
    return 1;
}
int main(void)
{
    int m=0,n=0,num[20000]={0};
    scanf("%d",&m);
    for(int i=2;i<m;i++)
    {
        if(sushu(i))
        {
            num[n]=i;
            n++;
        }
    }
    bubble_sort(num,n);
    for(int i=0;i<10;i++)
    {
        printf("%6d",num[i]);
    }
    return 0;
}