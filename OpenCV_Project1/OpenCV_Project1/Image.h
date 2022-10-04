#ifndef IMAGE_
#define IMAGE_

#include <opencv2/core/mat.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

class Image {
protected:
	cv::Mat image;
public:
	Image(cv::Mat image);
	Image(const Image& image);
	void set_image(cv::Mat image);
	cv::Mat get_image();
	virtual void write_image(std::string fileName, cv::Mat inputImage);
	virtual void show_image(std::string fileName, cv::Mat inputImage);
};

#endif