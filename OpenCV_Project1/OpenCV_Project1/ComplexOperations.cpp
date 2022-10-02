#include "ComplexOperations.h"
#include "MyException.h"

cv::Mat create_grasyscale_from_color_image(cv::Mat inputImage) {
	if (inputImage.data == NULL || inputImage.channels() < 3) {
		printf("Image is not loaded. Check for problems!");
		exit(EXIT_FAILURE);
	}
	int rows = inputImage.rows;
	int columns = inputImage.cols;
	cv::Mat grasyscaleImage(rows, columns, CV_8UC1);
	cv::Vec3b pixel = 0;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < columns; ++j) {
			pixel = inputImage.at<cv::Vec3b>(i, j);
			grasyscaleImage.at<uchar>(i, j) = (pixel[0] + pixel[1] + pixel[2]) / 3;
		}
	}
	return grasyscaleImage;
}


cv::Mat create_negative_image_from_grasyscale(cv::Mat inputImage) {
	if (inputImage.data == NULL || inputImage.channels() != 1) {
		printf("There is a problem with the image.Check for details!");
		exit(EXIT_FAILURE);
	}
	cv::Mat negativeImage(inputImage.rows, inputImage.cols, CV_8UC1);
	for (int i = 0; i < inputImage.rows; ++i) {
		for (int j = 0; j < inputImage.cols; ++j) {
			negativeImage.at<uchar>(i, j) = abs(255 - inputImage.at<uchar>(i, j));
		}
	}
	return negativeImage;
}

/*Changes the gray levels of a grayscale image. It can either do addition,
  or multiplication. The choice is based upon the variable "choose". If the sizeof(choose) is
  8(double) it means multiplication. If sizeof(choose) is 4(int) it is addition.*/
template<typename T>
cv::Mat change_gray_levels_for_grayscale_image(cv::Mat inputImage, T choose) {
	if (inputImage.data == NULL || inputImage.channels() != 1) {
		printf("There is a problem with the image. Check further!");
		exit(EXIT_FAILURE);
	}
	cv::Mat outputImage(inputImage.rows, inputImage.cols, CV_8UC1);
	if (sizeof(choose) == 4) {/* addition */
		for (int i = 0; i < inputImage.rows; ++i) {
			for (int j = 0; j < inputImage.cols; ++j) {
				outputImage.at<uchar>(i, j) = inputImage.at<uchar>(i, j) + choose;
			}
		}
	}
	else if (sizeof(choose) == 8) { /* Multiplication */
		for (int i = 0; i < inputImage.rows; ++i) {
			for (int j = 0; j < inputImage.cols; ++j) {
				outputImage.at<uchar>(i, j) = inputImage.at<uchar>(i, j) * choose;
			}
		}
	}
	return outputImage;
}

/*   When the compiler instantiates a templates, it creates a new class with the given arguments.
*    For this, the compiler needs to have acces to the implementation.
*    A solution would be to write the implementation in a header file.
*    Another solution is to write te implementation in a different file(not .cpp) and include it
* at the end of the header file.
*    The solution that I chose was to keep the implementation apart from the header file and to 
* explicitly instantiate the template instances that I would need.
*/
template cv::Mat change_gray_levels_for_grayscale_image<int>(cv::Mat inputImage, int choose);
template cv::Mat change_gray_levels_for_grayscale_image<double>(cv::Mat inputImage, double choose);