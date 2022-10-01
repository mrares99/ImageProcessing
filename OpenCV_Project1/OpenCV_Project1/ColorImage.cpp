#include "ColorImage.h"

ColorImage::ColorImage(cv::Mat inputImage) : Image(inputImage) {}

void ColorImage::transform_RGB_to_HSV() {
	cv::Mat inputImage = getImage();
	if (inputImage.channels() != 3) {
		printf("The image is not RGB. Please check.");
		exit(EXIT_FAILURE);
	}
	int imageRows = inputImage.rows, imageColumns = inputImage.cols;
	cv::Mat outputImage(imageRows, imageColumns, CV_8UC3);
	float r = 0, g = 0, b = 0;
	float value = 0, saturation = 0, hue = 0, diff = 0, minimum = 0, maximum = 0;
	cv::Vec3b pixel = 0;
	for (int i = 0; i < imageRows; ++i) {
		for (int j = 0; j < imageColumns; ++j) {
			pixel = inputImage.at<cv::Vec3b>(i, j);
			r = (float)pixel[2] / 255;
			g = (float)pixel[1] / 255;
			b = (float)pixel[0] / 255;
			//Value
			maximum = std::max({ r, g, b });
			value = maximum;
			minimum = std::min({ r, g, b });
			diff = maximum - minimum;
			//saturation
			if (value != 0) {
				saturation = diff / value;
			}
			else {
				saturation = 0;
			}
			//hue
			if (diff != 0) {
				if (maximum == r) {
					hue = 60 * (g - b) / diff;
				}
				if (maximum == g) {
					hue = 120 + 60 * (b - r) / diff;
				}
				if (maximum == b) {
					hue = 240 + 60 * (r - g) / diff;
				}
			}
			else {
				hue = 0;
			}
			if (hue < 0) {
				hue = hue + 360;
			}
			outputImage.at<cv::Vec3b>(i, j)[2] = value * 255;
			outputImage.at<cv::Vec3b>(i, j)[1] = saturation * 255;
			outputImage.at<cv::Vec3b>(i, j)[0] = hue * 255 / 360;
		}
	}
	setImage(outputImage);
}
