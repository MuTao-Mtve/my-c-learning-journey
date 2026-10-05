#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX_LENGTH 100
#define MIN_LENGTH 1
#define MIN_VALUE (-10000)
#define MAX_VALUE 10000
#define MIN_NUM_FUNCTION 0
#define MAX_NUM_FUNCTION 10
#define NUM_TAG 100000
int array_length=0,user_function_choice=0;
double array[MAX_LENGTH]={0};
//清空键盘缓冲区
void clear_buffer(void)
{
	int temp_variable=0;
	while((temp_variable=getchar())!='\n'&& temp_variable!=EOF);
} 
//注意两个输入函数的取值范围均为闭区间！
//获取整数输入
int int_get_input(int value_min,int value_max)
{
    double user_input=0;
    int ret=0;
    while(1)
    {
        ret=scanf("%lf",&user_input);
        if (ret==EOF)
        {
            printf("程序遇到EOF错误，请检查你的输入并重新启动程序！");
            system("pause");
            exit(0);
        }       
        else if (ret!=1||user_input>value_max||user_input<value_min)
        {
            printf("输入内容不合法！请重新输入\n");
            clear_buffer();
            continue;
        }
        else if (isnan(user_input))
        {
            printf("不支持输入NaN！请输入有效数字！\n");
            clear_buffer();
            continue;
        }
        else if (user_input != (int)user_input)
        {
            printf("仅支持整数输入！请重新输入\n");
            clear_buffer();
            continue;
        }
        else 
        {   
            clear_buffer();
            return((int)user_input);
        }
    }
}
//获取浮点数输入
double double_get_input(double value_max,double value_min)
{
    double user_input=0.0;
    int ret=0;
    while(1)
    {
        ret=scanf("%lf",&user_input);
        if (ret==EOF)
        {
            printf("程序遇到EOF错误，请检查你的输入并重新启动程序！");
            system("pause");
            exit(0);
        }       
        else if (ret!=1||user_input>value_max||user_input<value_min)
        {
            printf("输入内容不合法！请重新输入\n");
            clear_buffer();
            continue;
        }
        else if (isnan(user_input))
        {
            printf("不支持输入NaN！请输入有效数字！\n");
            clear_buffer();
            continue;
        }
        else 
        {   
            clear_buffer();
            return(user_input);
        }
    }
}
//开始菜单打印，用户功能选择
int print_menu(void)
{
    int user_function_choice=0;
    printf("=========== 一维数组综合管理器 ===========\n");
    printf("1. 显示当前数组\n");
    printf("2. 重新输入数组\n");
    printf("3. 统计信息：总和、平均值、最大值、最小值\n");
    printf("4. 升序排序并输出\n");
    printf("5. 降序排序并输出\n");
    printf("6. 查找某个值：输出出现次数和所有位置\n");
    printf("7. 删除指定位置的元素\n");
    printf("8. 在指定位置插入一个元素\n");
    printf("9. 删除所有等于指定值的元素\n");
    printf("10.数组去重，保留第一次出现的元素\n");
    printf("0. 退出程序\n");
    printf("=========================================\n");
    printf("请输入你的选择：\n");
    user_function_choice=int_get_input(MIN_NUM_FUNCTION,MAX_NUM_FUNCTION);
    return user_function_choice;
}
//所有分支结束的统一函数
void function_over(void)
{
    printf("本条指令执行完毕，即将返回初始菜单····\n");
    system("pause");
    system("cls");
}
//升序冒泡排序
void bubble_sort(double arr[],int n)
{
    double temp=0.0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
//降序冒泡排序
void reverse_bubble_sort(double arr[],int n)
{
    double temp=0.0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]<arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void array_print(void)
{
    printf("=========================================\n");
    for(int i=0;i<array_length;i++)
        {
            printf("第%d个元素为：%g\n",i+1,array[i]);
        }
    printf("=========================================\n");
}
void function_start(void)
{
    printf("=========================================\n");
    printf("你选择了功能 %d\n",user_function_choice);
    printf("=========================================\n");
}



int main(void)
{
    printf("欢迎使用一维数组综合管理器！\n初始化阶段····\n");
    printf("请先输入数组长度和数组元素，之后即可使用其他功能！\n");
    printf("请注意：数组长度范围为%d~%d，数组元素范围为%d~%d\n",MIN_LENGTH,MAX_LENGTH,MIN_VALUE,MAX_VALUE);
    printf("请注意：数组长度和数组元素仅支持输入整数和浮点数，且不支持NaN输入！\n");
    printf("请注意：数组长度和数组元素输入时请勿输入其他字符，否则会导致程序异常退出！\n");
    printf("======================================================================\n");
    printf("请输入数组长度：（范围：%d~%d，类型：仅支持整数！）\n",MIN_LENGTH,MAX_LENGTH);
    array_length=int_get_input(MIN_LENGTH,MAX_LENGTH);
    printf("======================================================================\n");
    printf("请依次输入数组元素：（范围：%d~%d，类型：双精度浮点数）\n",MIN_VALUE,MAX_VALUE);
    for(int i=0;i<array_length;i++)
    {
        printf("=========================================\n");
        printf("请输入第%d个元素：\n",i+1);
        array[i]=double_get_input(MAX_VALUE,MIN_VALUE);
        printf("=========================================\n");
    }
    system("cls");
    printf("初始化阶段结束，欢迎使用一维数组综合管理器！\n");
    while(1)
    {
        user_function_choice=print_menu();
        switch(user_function_choice)
        {
            case 0:
            {
                function_start();
                printf("感谢使用一维数组综合管理器！程序即将退出····\n");
                system("pause");
                exit(0);
            }
            case 1:
            {
                function_start();
                array_print();
                function_over();
                break;
            }
            case 2:
            {
                restart:
                function_start();
                printf("=========================================\n");
                printf("请输入新的数组长度：\n");
                array_length=int_get_input(MIN_LENGTH,MAX_LENGTH);
                printf("请依次输入数组元素：（范围：%d~%d，类型：双精度浮点数）\n",MIN_VALUE,MAX_VALUE);
                printf("=========================================\n");
                for(int i=0;i<array_length;i++)
                {
                    printf("=========================================\n");
                    printf("请输入第%d个元素：\n",i+1);
                    array[i]=double_get_input(MAX_VALUE,MIN_VALUE);
                }
                function_over();
                break;
            }
            case 3:
            {
                function_start();
                double sum=0,average=0,max=array[0],min=array[0];
                if(array_length<MIN_LENGTH)
                {
                    printf("数组长度小于最小值！无法执行功能3！即将进入功能2重新输入数组\n");
                    goto restart;
                }
                for(int i=0;i<array_length;i++)
                {
                    sum=sum+array[i];
                    if(array[i]>max)
                    {
                        max=array[i];
                    }
                    if(array[i]<min)
                    {
                        min=array[i];
                    }
                }
                average=sum/array_length;
                printf("=========================================\n");
                printf("数组总和：%g\n",sum);
                printf("数组平均值：%g\n",average);
                printf("数组最大值：%g\n",max);
                printf("数组最小值：%g\n",min);
                printf("=========================================\n");
                function_over();
                break;
            }
            case 4:
            {
                function_start();
                bubble_sort(array,array_length);
                array_print();
                function_over();
                break;
            }
            case 5:
            {
                function_start();
                reverse_bubble_sort(array,array_length);
                array_print();
                function_over();
                break;
            }
            case 6:
            {
                double num_find=0.0;
                int n=0,array_location[MAX_LENGTH]={0};
                function_start();
                printf("请输入你需要查询的数字：\n");
                num_find=double_get_input(MAX_VALUE,MIN_VALUE);
                for(int i=0;i<array_length;i++)
                {
                    if(array[i]==num_find)
                    {
                        array_location[i]=NUM_TAG;
                        n++;
                    }
                }
                if(n!=0)
                {
                    printf("数字%g在数组中出现了%d次\n这个数字出现在数组的",num_find,n);
                    for(int i=0;i<array_length;i++)
                    {
                        if(array_location[i]==NUM_TAG)
                        {
                            printf("第%d位 \n",i+1);
                            printf("============================================\n");
                        }
                    }
                    printf("\n");
                }
                else
                {
                    printf("数字%g在数组中未找到！\n",num_find);
                    printf("============================================\n");
                }
                function_over();
                break;
            }
            case 7:
            {
                function_start();
                if(array_length<=1)
                {
                    printf("数组长度为最小值，无法进行删除！\n");
                    printf("=========================================\n");
                    function_over();
                    break;
                }
                int num_location=NUM_TAG;
                array_print();
                printf("请输入要删除的数的位置：（数组下标从 1 开始）");
                num_location=(int_get_input(MIN_LENGTH,array_length))-1;
                printf("=========================================\n");
                for(num_location;num_location<array_length-1;num_location++)//i<array_length-1是为了防止array[num_location]=array[num_location+1];这个C语句造成越界
                {
                    array[num_location]=array[num_location+1];
                }
                array_length--;
                array[array_length]=0.0; //重置array[array_length]以修复隐藏的安全漏洞，防止隐私泄露
                printf("删除成功！");
                array_print();
                function_over();
                break;
            }
            case 8:
            {
                int array_location=NUM_TAG;
                double user_input=0.0;
                function_start();
                if(array_length>=MAX_LENGTH)
                {
                    printf("数组长度已经达到最大限制，无法插入！\n");
                    function_over();
                    break;
                }
                else
                {
                    printf("请输入需要插入的位置：\n");
                    array_location=(int_get_input(MIN_LENGTH,array_length+1))-1;
                    printf("=========================================\n");
                    printf("请输入要插入的数值：\n");
                    user_input=double_get_input(MAX_VALUE,MIN_VALUE);
                    printf("=========================================\n");
                    if(array_location!=array_length)
                    {
                        for(int i=(array_length-1);i>=array_location;i--)
                        {
                            array[i+1]=array[i];
                        }
                    }
                    array_length++;
                    array[array_location]=user_input;
                    printf("操作成功！\n");
                    array_print();
                    function_over();
                    break;
                }
            }
            case 9:
            {
                double num_del=NUM_TAG;
                int num_location=NUM_TAG,num_deleted=0,i=0,j=0;
                function_start();
                printf("请输入需要删除的数值：\n");
                num_del=double_get_input(MAX_VALUE,MIN_VALUE);
                while(i<array_length)
                {
                    j=i;
                    if(array[j]==num_del)
                    {
                        num_location=j;
                        for(num_location;num_location<array_length-1;num_location++)
                        {
                            array[num_location]=array[num_location+1];
                        }
                        array_length--;
                        num_deleted++;
                    }
                    else
                    {
                        i++;
                    }
                }
                if(num_deleted!=0&&array_length!=0)
                {
                    printf("=========================================\n");
                    printf("操作成功！共计删除了%d个元素\n",num_deleted);
                    printf("=========================================\n");
                    array_print();
                }
                else if(num_deleted!=0&&array_length==0)
                {
                    printf("=========================================\n");
                    printf("操作成功！共计删除了%d个元素\n",num_deleted);
                    printf("=========================================\n");
                    printf("请注意：数组长度已经小于最小值，请选择功能2再次输入数组！\n");
                    printf("=========================================\n");
                    goto restart;
                }
                else
                {
                    printf("=========================================\n");
                    printf("操作失败！未在数组中找到%g\n",num_del);
                    printf("=========================================\n");
                }
                if(array_length<MAX_LENGTH)
                {
                    array[array_length]=0.0;
                }
                function_over();
                break;
            }
            case 10:
            {
                function_start();
                double temp_array[MAX_LENGTH]={0.0};
                int num_NUM_TAG=0,i=0,j=0;
                while(num_NUM_TAG!=array_length)
                {
                    if(array[j]==NUM_TAG)
                    {
                        j++;
                        continue;
                    }
                    else
                    {
                        temp_array[i]=array[j];
                        for(int n=0;n<array_length;n++)
                        {
                            if(array[n]==temp_array[i])
                            {
                                array[n]=NUM_TAG;
                                num_NUM_TAG++;
                            }
                        }
                        i++;
                    }
                }
                for(int n=0;n<MAX_LENGTH;n++)
                {
                    array[n]=0.0;
                }
                for(int n=0;n<i;n++)
                {
                    array[n]=temp_array[n];
                }
                array_length=i;
                printf("=========================================\n");
                printf("操作成功！\n数组已成功去重！\n");
                printf("=========================================\n");
                array_print();
                function_over();
                break;
            }
            default :
            {
                printf("=========================================\n");
                printf("请输入正确的功能代码！\n类型：整数\n范围0~10\n");
                printf("=========================================\n");
                function_over();
                break;
            }
        }
    }   
    return(0);
}
