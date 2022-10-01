#include "Image.h"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

Image::Image(cv::Mat inputImage) {
	this->image = inputImage.clone();
}

void Image::write_image(std::string name) {
	cv::imwrite(name, image);
}

void Image::show_image(std::string nameOfWindow) {
	cv::imshow(nameOfWindow, image);
}

cv::Mat Image::getImage() {
	return image;
}

void Image::setImage(cv::Mat inputImage) {
	image = inputImage.clone();
}