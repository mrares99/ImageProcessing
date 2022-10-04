#ifndef GRAYSCALE_IMAGE_
#define GRAYSCALE_IMAGE_

#include "Image.h"

class GrayscaleImage : public Image {

public:
	GrayscaleImage(cv::Mat grayscaleImage);
};

#endif