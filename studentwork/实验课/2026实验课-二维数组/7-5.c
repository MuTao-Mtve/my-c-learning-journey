#include <stdio.h>
int is_anpoint(int n,int arr[n][n],int i,int j)
{
    int temp=arr[i][j],max=arr[i][j],min=arr[i][j];
    for(int k=0;k<n;k++) if(max<arr[i][k]) max=arr[i][k];
    for(int k=0;k<n;k++) if(min>arr[k][j]) min=arr[k][j];
    if(temp==max && temp==min) return 1;
    else return 0;
}
int main(void)
{
    int n;
    scanf("%d",&n);
    int arr[n][n];
    int *p=&arr[0][0];
    for(int i=0;i<n*n;i++)
    {
        scanf("%d",p);
        p++;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(is_anpoint(n,arr,i,j))
            {
                printf("%d %d",i,j);
                goto end;
            }
        }
    }
    printf("NONE");
    end:
    return 0;
}