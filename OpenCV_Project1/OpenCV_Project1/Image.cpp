#include "Image.h"


Image::Image(cv::Mat image) : image{ image } {
}

Image::Image(const Image& image) {
	this->image = image.image.clone();
}

void Image::set_image(cv::Mat image) {
	this->image = image.clone();
}

cv::Mat Image::get_image() {
	return image;
}

void Image::write_image(std::string fileName, cv::Mat inputImage) {
	cv::imwrite(fileName, inputImage);
}

void Image::show_image(std::string fileName, cv::Mat inputImage) {
	cv::imshow(fileName, inputImage);
}