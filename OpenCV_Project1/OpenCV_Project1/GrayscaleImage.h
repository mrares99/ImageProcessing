#ifndef GRAYSCALE_IMAGE_ 
#define GRAYSCALE_IMAGE_

#include "GrayscaleImage.h"
#include "Image.h"

class GrayscaleImage : public Image {

public:
	GrayscaleImage(cv::Mat inputImage);
	void transform_to_binary(int threshold);
};

#endif