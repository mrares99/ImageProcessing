#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include "ColorImage.h"
#include <thread>

using namespace cv;

int main()
{
    cv::Mat inputImage = cv::imread("D:/ImageProcessingProjects/Images/LennaRGB512.png");
    ColorImage colorImage{ inputImage };
    
    std::thread th1(colorImage, 0);
    std::thread th2(colorImage, 1);
    std::thread th3(colorImage, 2);

    th1.join();
    th2.join();
    th3.join();

    colorImage.show_image("Blue channel", colorImage.get_blue_channel());
    colorImage.show_image("Green channel", colorImage.get_green_channel());
    colorImage.show_image("Red channel", colorImage.get_red_channel());

    waitKey(0);
    return 0;
}