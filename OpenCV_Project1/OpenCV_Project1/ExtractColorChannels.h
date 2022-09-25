#ifndef EXTRACT_COLOR_CHANNELS_
#define EXTRACT_COLOR_CHANELLS_

#include <opencv2/core/mat.hpp>

cv::Mat extract_red_channel(cv::Mat inputMatrix);
cv::Mat extract_green_channel(cv::Mat inputMatrix);
cv::Mat extract_blue_channel(cv::Mat inputMatrix);

#endif
