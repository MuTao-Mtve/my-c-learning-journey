#include <stdio.h>

int main(void)
{
    double length = 0.0, price = 0.0;
    int num_time = 0;
    int time_wait = 0;
    

    scanf("%lf %d", &length, &time_wait);
    

    num_time = time_wait / 5;
    

    if (length <= 3.0) {
        price = 10 + num_time * 2;
    } 
    else if (length <= 10.0) {
        price = 10 + (length - 3.0) * 2 + num_time * 2;
    } 
    else { // 涵盖大于 10.0 的情况 (前10公里费用为10+7*2=24元)
        price = 24 + (length - 10.0) * 3 + num_time * 2;
    }
    
    printf("%d\n", (int)(price + 0.5));
    
    return 0;
}