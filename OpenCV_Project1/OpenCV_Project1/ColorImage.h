#ifndef COLOR_IMAGE_
#define COLOR_IMAGE_

#include "Image.h"

class ColorImage : public Image {
	cv::Mat colorChannels[3];//BGR stored
public:
	ColorImage(cv::Mat colorImage);
	void operator()(int colorChannel);
	cv::Mat get_red_channel();
	cv::Mat get_green_channel();
	cv::Mat get_blue_channel();
	void write_image(std::string fileName, cv::Mat inputImage);
	void show_image(std::string fileName, cv::Mat inputImage);
};

#endif
