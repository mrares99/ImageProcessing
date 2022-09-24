#include "BasicOperations.h"
#include <opencv2/imgcodecs.hpp>
#include "MyException.h"

cv::Mat read_image(const char* path)
{
	try {
		cv::Mat temp = cv::imread(path, cv::IMREAD_UNCHANGED);
		if (temp.data == NULL) {
			throw MyException("Image not loaded.", __LINE__, "BasicOperations.cpp",
				"read_image", "The image was not loaded. Check for possible problems.");
		}
	}
	catch (MyException& ex) {
		ex.print_fields();
	}
}

void write_image(const std::string name, const cv::Mat mat)
{
	try {
		if (mat.empty()) {
			throw MyException("Image not existent.", __LINE__, "BasicOperations.cpp",
				"write_image", "Content not available.");
		}

		cv::imwrite(name, mat);
	}
	catch (MyException& ex) {
		ex.print_fields();
	}
}