#include "ExtractColorChannels.h"
#include "MyException.h"

cv::Mat extract_red_channel(cv::Mat inputMatrix){
	try {
		if (inputMatrix.channels() != 3) { /*If the image is not a RGB one, then print error.*/
			throw MyException("Image does not have 3 color channels", __LINE__,
				"ExtractCOlorChannels.cpp", "extract_red_channels",
				"Image does not have 3 color channels");
		}
		else {
			int lines = inputMatrix.rows;
			int columns = inputMatrix.cols;
			cv::Mat red_channel(lines, columns, CV_8UC3);
			cv::Vec3b pixel;
			for (int i = 0; i < lines; ++i) {
				for (int j = 0; j < columns; ++j) {
					pixel = inputMatrix.at<cv::Vec3b>(i, j);
					red_channel.at<cv::Vec3b>(i, j)[2] = pixel[2];
				}
			}
			return red_channel;
		}
	}
	catch (MyException &ex) {
		ex.print_fields();
	}
}

cv::Mat extract_green_channel(cv::Mat inputMatrix) {
	try {
		if (inputMatrix.channels() != 3) { /*If the image is not a RGB one, then print error.*/
			throw MyException("Image does not have 3 color channels", __LINE__,
				"ExtractCOlorChannels.cpp", "extract_red_channels",
				"Image does not have 3 color channels");
		}
		else {
			int lines = inputMatrix.rows;
			int columns = inputMatrix.cols;
			cv::Mat green_channel(lines, columns, CV_8UC3);
			cv::Vec3b pixel;
			for (int i = 0; i < lines; ++i) {
				for (int j = 0; j < columns; ++j) {
					pixel = inputMatrix.at<cv::Vec3b>(i, j);
					green_channel.at<cv::Vec3b>(i, j)[1] = pixel[1];
				}
			}
			return green_channel;
		}
	}
	catch (MyException& ex) {
		ex.print_fields();
	}
}

cv::Mat extract_blue_channel(cv::Mat inputMatrix) {
	try {
		if (inputMatrix.channels() != 3) { /*If the image is not a RGB one, then print error.*/
			throw MyException("Image does not have 3 color channels", __LINE__,
				"ExtractCOlorChannels.cpp", "extract_red_channels",
				"Image does not have 3 color channels");
		}
		else {
			int lines = inputMatrix.rows;
			int columns = inputMatrix.cols;
			cv::Mat blue_channel(lines, columns, CV_8UC3);
			cv::Vec3b pixel;
			for (int i = 0; i < lines; ++i) {
				for (int j = 0; j < columns; ++j) {
					pixel = inputMatrix.at<cv::Vec3b>(i, j);
					blue_channel.at<cv::Vec3b>(i, j)[0] = pixel[0];
				}
			}
			return blue_channel;
		}
	}
	catch (MyException& ex) {
		ex.print_fields();
	}
}


