#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include "MyException.h"
#include "BasicOperations.h"
using namespace cv;

int main()
{
    cv::Mat inputImage = read_image("D:/ImageProcessingProjects/Images/LennaRGB512.png");
    write_image("D:/ImageProcessingProjects/Images/LenaRGB512Output.png", inputImage);
    return 0;
}