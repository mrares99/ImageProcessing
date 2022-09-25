#ifndef COMPLEX_OPERATIONS_
#define COMPLEX_OPERATIONS_

#include <opencv2/core/mat.hpp>

cv::Mat create_grasyscale_from_color_image(cv::Mat inputImage);
cv::Mat create_negative_image_from_grasyscale(cv::Mat inputImage);

template<typename T>
cv::Mat change_gray_levels_for_grayscale_image(cv::Mat inputImage, T choose);

#endif