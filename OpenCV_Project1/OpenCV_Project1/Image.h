#ifndef IMAGE_
#define IMAGE_

#include <opencv2/core/mat.hpp>

class Image {
private:
	cv::Mat image;
public:
	Image(cv::Mat inputImage);
	void write_image(std::string name);
	void show_image(std::string nameOfWindow);
	cv::Mat getImage();
	void setImage(cv::Mat inputImage);
};

#endif