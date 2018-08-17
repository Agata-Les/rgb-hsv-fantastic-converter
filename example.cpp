#include "rgb_hsv_converter.h"
#include <iostream>

int main()
{
	RGB rgbColour { 255, 0, 0 };
	HSV hsvColour { 120, 100, 100 };

	std::cout<<"RGB: "<<rgbColour<<" = HSV: "<<convert_RGB_to_HSV(rgbColour)<<std::endl;
	std::cout<<"HSV: "<<hsvColour<<" = RGB: "<<convert_HSV_to_RGB(hsvColour)<<std::endl;

	return 0;
}