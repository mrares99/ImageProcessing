#include "MultithreadedImage.h"

MultithreadedImage::MultithreadedImage(cv::Mat inputImage) : colorImage{ inputImage } {
	if (arrayOfColorChannels[0].data == NULL) {
		arrayOfColorChannels[0] = cv::Mat(colorImage.rows, colorImage.cols,
			CV_8UC3, 0.0);
	}

	if (arrayOfColorChannels[1].data == NULL) {
		arrayOfColorChannels[1] = cv::Mat(colorImage.rows, colorImage.cols,
			CV_8UC3, 0.0);
	}

	if (arrayOfColorChannels[2].data == NULL) {
		arrayOfColorChannels[2] = cv::Mat(colorImage.rows, colorImage.cols,
			CV_8UC3, 0.0);
	}
}

void MultithreadedImage::setColorImage(cv::Mat inputImage) {
	colorImage = inputImage.clone();
	if (arrayOfColorChannels[0].data == NULL) {
		arrayOfColorChannels[0] = cv::Mat(colorImage.rows, colorImage.cols,
			CV_8UC3, 0.0);
	}

	if (arrayOfColorChannels[1].data == NULL) {
		arrayOfColorChannels[1] = cv::Mat(colorImage.rows, colorImage.cols,
			CV_8UC3, 0.0);
	}

	if (arrayOfColorChannels[2].data == NULL) {
		arrayOfColorChannels[2] = cv::Mat(colorImage.rows, colorImage.cols,
			CV_8UC3, 0.0);
	}
}

void MultithreadedImage::operator()(int colorChannel, bool isExtraction) {
	if (colorChannel < 0 || colorChannel > 2) {
		printf("Wrong color channel. Choose more careful.");
		exit(EXIT_FAILURE);
	}
	if (isExtraction == true) {
		for (int i = 0; i < colorImage.rows; ++i) {
			for (int j = 0; j < colorImage.cols; ++j) {
				arrayOfColorChannels[colorChannel].at<cv::Vec3b>(i, j)[colorChannel] =
					colorImage.at<cv::Vec3b>(i, j)[colorChannel];
			}
		}
	}
	else {
		for (int i = 0; i < colorImage.rows; ++i) {
			for (int j = 0; j < colorImage.cols; ++j) {
				colorImage.at<cv::Vec3b>(i, j)[colorChannel] =
					arrayOfColorChannels[colorChannel].at<cv::Vec3b>(i, j)[colorChannel];
			}
		}
	}
}


cv::Mat MultithreadedImage::getRedChannel() {
	return arrayOfColorChannels[2];
}

cv::Mat MultithreadedImage::getGreenChannel() {
	return arrayOfColorChannels[1];
}

cv::Mat MultithreadedImage::getBlueChannel() {
	return arrayOfColorChannels[0];
}

cv::Mat MultithreadedImage::getColorImage() {
	return colorImage;
}