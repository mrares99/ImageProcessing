#ifndef MULTITHREADED_IMAGE_
#define MULTITHREADED_IMAGE_

#include <opencv2/core/mat.hpp>

class MultithreadedImage {
private:
	cv::Mat colorImage;
	cv::Mat arrayOfColorChannels[3]; // They will have the arrangement BLUE, GREEN, RED
public:
	MultithreadedImage(cv::Mat inputImage);
	void operator()(int colorChannel, bool isExtraction);
	cv::Mat getRedChannel();
	cv::Mat getGreenChannel();
	cv::Mat getBlueChannel();
	void setColorImage(cv::Mat colorImage);
	cv::Mat getColorImage();
};

#endif