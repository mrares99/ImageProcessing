#ifndef COLOR_IMAGE_
#define COLOR_IMAGE_

#include "ColorImage.h"
#include "Image.h"

class ColorImage : public Image {
public:
	ColorImage(cv::Mat inputImage);
	void transform_RGB_to_HSV();
};

#endif