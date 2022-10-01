#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include "MyException.h"
#include "BasicOperations.h"
#include "PointerOperations.h"
#include "ComplexOperations.h"
#include "Image.h"
#include "GrayscaleImage.h"
#include "ColorImage.h"

using namespace cv;

int main()
{
    cv::Mat inputImage = read_image("D:/ImageProcessingProjects/Images/LennaRGB512.png");
    write_image("D:/ImageProcessingProjects/Images/LenaRGB512Output.png", inputImage);
    cv::Mat grayscale = create_grasyscale_from_color_image(inputImage);
    write_image("D:/ImageProcessingProjects/Images/LenaRGB512Grayscale.png", grayscale);
    cv::Mat negativeImageFromGrasyscale = create_negative_image_from_grasyscale(grayscale);
    write_image("D:/ImageProcessingProjects/Images/LenaRGB512Negative.png", negativeImageFromGrasyscale);
    cv::Mat changeGrayscaleLevels = change_gray_levels_for_grayscale_image(grayscale, 90);
    write_image("D:/ImageProcessingProjects/Images/LenaRGB512ChangeLevels.png", changeGrayscaleLevels);
    
    GrayscaleImage grayscaleImage{ grayscale };
    grayscaleImage.transform_to_binary(150);
    cv::imshow("Binary Transformation", grayscaleImage.getImage());

    ColorImage colorImage{ inputImage };
    colorImage.transform_RGB_to_HSV();
    cv::imshow("RGB to HSV transformation", colorImage.getImage());


    waitKey(0);
    return 0;
}