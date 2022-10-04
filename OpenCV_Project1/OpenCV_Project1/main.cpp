#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include "MyException.h"
#include "BasicOperations.h"
#include "PointerOperations.h"
#include "ComplexOperations.h"
#include "MultithreadedImage.h"
#include <thread>

using namespace cv;

void do_something(int* var) {
    var = (int*)malloc(sizeof(int));
    *var = 12;
}

int main()
{
    int variable = 10;
    do_something(&variable);
    std::cout << variable;
    return 0;
}