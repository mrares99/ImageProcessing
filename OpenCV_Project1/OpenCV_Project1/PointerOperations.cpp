#include "PointerOperations.h"
#include <stdlib.h>
#include <stdio.h>

/*With the following three functions I showed that I could call a function
only from within another one, by using #define preprocesor instruction.
Note that this is not a way to create a private function.*/
void print_result(int a) {
	printf("The result is: %d\n", a);
}

#define f print_result
void add_two_numbers(int a, int b) {
	f(a + b);
}
#undef f

void add_three_numbers(int a, int b, int c) {
	print_result(a + b + c);
	//f(a + b + c); //Error
}


int* allocate_memory_for_1D_array(const int numberOfElements) {
	if (numberOfElements <= 0) {
		return NULL;
	}
	return (int*)calloc(numberOfElements, sizeof(int));
}

void populate_array(int* arrayOfNumbers, int numberOfElements) {
	if (arrayOfNumbers != NULL) {
		for (int i = 0; i < numberOfElements; ++i) {
			*(arrayOfNumbers + i) = i;
		}
	}
	else {
		printf("Invalid input array");
	}
}

void print_array_values(int* arrayOfNumbers, int numberOfElements) {
	if (arrayOfNumbers != NULL) {
		for (int i = 0; i < numberOfElements; ++i) {
			printf("%d ", *(arrayOfNumbers + i));
		}
	}
	else {
		printf("Invalid input array");
	}
}


/*Strange Pointer Arithmetic ???
*(arrayOfElements + i) = arrayOfElements[i];

*(arrayOfElements + i) = *(i + arrayOfElements) = i[arrayOfElements];

EX:
*(arrayOFElements + 2) = *(2 + arrayOfElements) = 2[arrayOfElements];

*/
void print_array_values_the_strange_way(int* arrayOfElements, int numberOfElements) {
	if (arrayOfElements != NULL) {
		for (int i = 0; i < numberOfElements; ++i) {
			//printf("%d ", arrayOfElements[i]);
			printf("%d ", i[arrayOfElements]);
		}
	}
	else {
		printf("Invalid input array");
	}
}



