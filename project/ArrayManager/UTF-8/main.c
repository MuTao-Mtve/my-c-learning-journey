#include "prearr.h"

int main (void)
{
    int array_length=0,user_function_choice=0;
    double array[MAX_LENGTH]={0};
    int *p_length=&array_length,*p_user_function_choice=&user_function_choice;
    initialize(p_length,array);
    while(1)
    {
        print_menu ();
        get_user_choice(p_user_function_choice);
        function_start(*p_user_function_choice);
        switch (user_function_choice)
        {
            case 0:
            {
                program_exit ();
                break;
            }
            case 1:
            {
                array_print (array,*p_length);
                break;
            }
            case 2:
            {
                pre_initialize (p_length,array);
                array_print (array,*p_length);
                break;
            }
            case 3:
            {
                statistics (array,*p_length);
                break;
            }
            case 4:
            {
                sort_NormalOrder(array,array_length);
                break;
            }
            case 5:
            {
                sort_ReverseOrder(array,array_length);
                break;
            }
            case 6:
            {
                search_num (*p_length,array);
                break;
            }
            case 7:
            {
                delete_element_by_location (p_length,array);
                array_print (array,*p_length);
                break;
            }
            case 8:
            {
                insert_element (p_length,array);
                array_print (array,*p_length);
                break;
            }
            case 9:
            {
                delete_elements_by_value (p_length,array);
                break;
            }
            case 10:
            {
                array_unique (p_length,array);
                array_print (array,*p_length);
                break;
            }
        }
        function_over();
        continue;
    }
    return 0;
}