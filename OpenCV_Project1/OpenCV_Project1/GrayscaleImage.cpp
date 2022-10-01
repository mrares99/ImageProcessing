#include "GrayscaleImage.h"

GrayscaleImage::GrayscaleImage(cv::Mat inputImage) : Image(inputImage) {}

void GrayscaleImage::transform_to_binary(int threshold) {
	if (getImage().channels() != 1) {
		printf("Image not correct.");
		exit(EXIT_FAILURE);
	}
	cv::Mat temp = getImage();
	for (int i = 0; i < temp.rows; ++i) {
		for (int j = 0; j < temp.cols; ++j) {
			if (temp.at<uchar>(i, j) < threshold) {
				temp.at<uchar>(i, j) = 0;
			}
			else {
				temp.at<uchar>(i, j) = 255;
			}
		}
	}
	setImage(temp);
}