#include <stdio.h>
void bubble_sort(int arr[], int n)
{
    int temp=0;
    for (int i=0;i<n-1;i++)
    {
        for (int j=0;j<n-i-1;j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main(void)
{   
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf(" %d",&a[i]);
    bubble_sort(a,n);
    printf("min = %d",a[0]);
    return 0;
}