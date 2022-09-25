#ifndef BASIC_OPERATIONS_
#define BASIC_OPERATIONS_

#include <opencv2/core/mat.hpp>

cv::Mat read_image(const char* path);
void write_image(const std::string name, const cv::Mat mat);

#endif