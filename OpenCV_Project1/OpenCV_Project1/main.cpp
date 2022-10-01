#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include "MyException.h"
#include "BasicOperations.h"
#include "PointerOperations.h"
using namespace cv;

int main()
{
    int numberOfElements = 0;
    printf("Enter the number of elements: ");
    scanf_s("%d", &numberOfElements);
    int *arrayOfElements = allocate_memory_for_1D_array(numberOfElements);
    populate_array(arrayOfElements, numberOfElements);
    print_array_values(arrayOfElements, numberOfElements);
    printf("\nStranger things:");
    print_array_values_the_strange_way(arrayOfElements, numberOfElements);

    add_two_numbers(2, 4);
    add_three_numbers(2, 2, 3);
    return 0;
}