#include <stdio.h>
#include <string.h>
#define MAX1 1
#define MAX2 9
#define MAX3 9
int main()
{
    char s1[MAX1+1];
    char s2[MAX2+1];
    char s3[MAX3+1];
     int n1,n2,n3;
     char grade;
     gets( s1 );
     gets( s2 );
     gets( s3 );
     n1 = strlen(s1) - 1; //计算出百位的数字
     n2 = strlen(s2) - 1; //计算出十位的数字
     n3 = strlen(s3) - 1;//计算出个位的数字
     switch(n2){
         case 6:grade = 'D'; break;
         case 7:grade = 'C'; break;
         case 8:grade = 'B'; break;
         case 9:grade = 'A'; break;
         default: grade = 'E';break;
     }
     if(n1==1){
        grade = 'A';
     }
     printf("%c\n",grade);
     return 0;
}
