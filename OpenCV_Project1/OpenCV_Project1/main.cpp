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

int function(int variable) {
    variable = 0;
    return variable++;
}

int main()
{
    int variable = -1;
    std::cout << function(variable);
    return 0;
}