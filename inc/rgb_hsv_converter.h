#pragma once

#include "hsv.h"
#include "rgb.h"

HSV convert_RGB_to_HSV(const RGB & RGBValues);
unsigned short int calculateValue(const unsigned short int max);
unsigned short int calculateHue(const RGB & val);
unsigned short int calculateSaturation(const unsigned short int min, const unsigned short int max);
