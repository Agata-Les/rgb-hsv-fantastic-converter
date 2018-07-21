#pragma once

#include "hsv.h"
#include "rgb.h"

HSV convert_RGB_to_HSV(const RGB & RGBValues);
RGB convert_HSV_to_RGB(const HSV & HSVValues);
float calculateValue(const unsigned short int max);
unsigned short int calculateHue(const RGB & val);
float calculateSaturation(const unsigned short int min, const unsigned short int max);
