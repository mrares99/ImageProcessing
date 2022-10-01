#ifndef POINTER_OPERATIONS_
#define POINTER_OPERATIONS_


/*With the following three functions I will shwo that I can call a function
only from within another one, by using #define preprocesor instruction.
Note that this is not a way to create a private function.*/
void add_two_numbers(int a, int b);
void print_result(int a);
void add_three_numbers(int a, int b, int c);


int* allocate_memory_for_1D_array(int numberOfElements);
void populate_array(int* arrayOfNumbers, int numberOfElements);
void print_array_values(int* arrayOfNumbers, int numberOfElements);
void print_array_values_the_strange_way(int* arrayOfElements, int numberOfElements);



#endif 