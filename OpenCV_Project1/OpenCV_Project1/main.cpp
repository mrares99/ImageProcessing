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
    cv::imshow("Input image", inputImage);
    MultithreadedImage multithreadedImage{inputImage};


    std::thread th1(multithreadedImage, 0, true);
    std::thread th2(multithreadedImage, 1, true);
    std::thread th3(multithreadedImage, 2, true);
    
    th1.join();
    th2.join();
    th3.join();
    
    cv::Mat redChannel = multithreadedImage.getRedChannel();
    cv::Mat greenChannel = multithreadedImage.getGreenChannel();
    cv::Mat blueChannel = multithreadedImage.getBlueChannel();

    cv::imshow("Red channel", redChannel);
    cv::imshow("Green channel", greenChannel);
    cv::imshow("Blue channel", blueChannel);



    multithreadedImage.setColorImage(cv::Mat(inputImage.rows,
        inputImage.cols, CV_8UC3, 0.0));

    std::thread th4(multithreadedImage, 0, false);
    std::thread th5(multithreadedImage, 1, false);
    std::thread th6(multithreadedImage, 2, false);

    th4.join();
    th5.join();
    th6.join();
    cv::imshow("COmbined chanels", multithreadedImage.getColorImage());

    waitKey(0);
    return 0;
}