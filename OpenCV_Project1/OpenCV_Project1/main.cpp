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

int main()
{
    cv::Mat inputImage = read_image("D:/ImageProcessingProjects/Images/LennaRGB512.png");
    MultithreadedImage multithreadedImage{inputImage};
    //multithreadedImage.setColorImage(inputImage);

    //cv::Mat readImage = multithreadedImage.getColorImage();
    //imshow("readImage", readImage);
    //The image is read correctly.


    std::thread th1(multithreadedImage, 0);
    std::thread th2(multithreadedImage, 1);
    std::thread th3(multithreadedImage, 2);
    
    th1.join();
    th2.join();
    th3.join();
    
    cv::Mat redChannel = multithreadedImage.getRedChannel();
    cv::Mat greenChannel = multithreadedImage.getGreenChannel();
    cv::Mat blueChannel = multithreadedImage.getBlueChannel();

    cv::imshow("Red channel", redChannel);
    cv::imshow("Green channel", greenChannel);
    cv::imshow("Blue channel", blueChannel);

    waitKey(0);
    return 0;
}