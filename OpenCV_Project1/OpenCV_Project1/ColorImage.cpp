#include "ColorImage.h"

ColorImage::ColorImage(cv::Mat colorImage) : Image(colorImage) {
	colorChannels[0] = cv::Mat(colorImage.rows, colorImage.cols, CV_8UC3);
	colorChannels[1] = cv::Mat(colorImage.rows, colorImage.cols, CV_8UC3);
	colorChannels[2] = cv::Mat(colorImage.rows, colorImage.cols, CV_8UC3);
}

void ColorImage::operator()(int colorChannel) {
	if (colorChannel < 0 || colorChannel > 3) {
		std::cout << "Wrong channel number";
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < image.rows; i++) {
		for (int j = 0; j < image.cols; ++j) {
			colorChannels[colorChannel].at<cv::Vec3b>(i, j)[colorChannel] =
				image.at<cv::Vec3b>(i, j)[colorChannel];
		}
	}
}

cv::Mat ColorImage::get_red_channel() {
	if (colorChannels[2].data == NULL) {
		std::cout << "Empty image";
		exit(EXIT_FAILURE);
	}
	return colorChannels[0];
}

cv::Mat ColorImage::get_green_channel() {
	if (colorChannels[1].data == NULL) {
		std::cout << "Empty image";
		exit(EXIT_FAILURE);
	}
	return colorChannels[1];
}

cv::Mat ColorImage::get_blue_channel() {
	if (colorChannels[0].data == NULL) {
		std::cout << "Empty image";
		exit(EXIT_FAILURE);
	}
	return colorChannels[2];
}



void ColorImage::write_image(std::string fileName, cv::Mat inputImage) {
	cv::imwrite(fileName, inputImage);
}

void ColorImage::show_image(std::string fileName, cv::Mat inputImage) {
	cv::imshow(fileName, inputImage);
}