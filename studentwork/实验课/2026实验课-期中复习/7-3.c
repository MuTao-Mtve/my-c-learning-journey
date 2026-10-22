#include <stdio.h>
int main(void)
{
    double apple=3.00,pear=2.50,orange=4.10,grape=10.20;
    int user_chioce;
    printf("[1] apple\n[2] pear\n[3] orange\n[4] grape\n[0] exit\n");
    for(int i=0;i<5;i++)
    {
        scanf(" %d",&user_chioce);
        switch(user_chioce)
        {
            case 0:
                return 0;
            case 1:
                printf("price = %.2lf\n",apple);
                break;
            case 2:
                printf("price = %.2lf\n",pear);
                break;
            case 3:
                printf("price = %.2lf\n",orange);
                break;
            case 4:
                printf("price = %.2lf\n",grape);
                break;
            default :
                printf("price = 0.00\n");
                break;
        }
    }
    return 0;
}