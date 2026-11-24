#ifndef PREARR_H
#define PREARR_H

#define MAX_LENGTH 100
#define MIN_LENGTH 1
#define MIN_VALUE (-10000)
#define MAX_VALUE 10000
#define MIN_NUM_FUNCTION 0
#define MAX_NUM_FUNCTION 10
#define NUM_TAG 100000
#define INT_CHOICE 1
#define FLOAT_CHOICE 2


void clear_buffer (void);
double get_user_input (double max_value, double min_value, int function_selection);
int get_user_int_input(double max_value, double min_value);
void print_menu(void);
void get_user_choice (int *p);
void function_over(void);
int compar_NormalOrder(const void *a,const void *b);
int compar_ReverseOrder(const void *a,const void *b);
void sort_NormalOrder(double arr[],int arr_length);
void sort_ReverseOrder(double arr[],int arr_length);
void array_print(double arr[],int arr_length);
void function_start(int user_function_chose);
void pre_initialize (int *p_length,double arr[]);
void initialize (int *p_length,double arr[]);
void program_exit (void);
void statistics (double array[],int arr_length);
void search_num (int arr_length,double array[]);
void delete_element_by_location (int *p_length,double array[]);
void insert_element (int *p_length,double array[]);
void delete_elements_by_value(int *p_length,double array[]);
void array_unique(int *p_length,double array[]);

#endif