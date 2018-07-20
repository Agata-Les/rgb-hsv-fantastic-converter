#include "rgb_hsv_converter.h"
#include <utility>

HSV convert_RGB_to_HSV(const RGB & RGBValues)
{
	HSV result {};

	const int minimalValueOfColour = std::min(std::min(RGBValues.Red, RGBValues.Blue), RGBValues.Green);
	const int maximalValueOfColour = std::max(std::max(RGBValues.Red, RGBValues.Blue), RGBValues.Green);

	result.Value = calculateValue(maximalValueOfColour);
	result.Hue = calculateHue(minimalValueOfColour, maximalValueOfColour, RGBValues);
	result.Saturation = calculateSaturation(minimalValueOfColour, maximalValueOfColour, RGBValues);

	return result;
}

unsigned short int calculateValue(const int max)
{
	return (100 * max) / 255;
}

unsigned short int calculateHue(const int min, const int max, const RGB & val)
{
	if(min == max) return 0;

	int resultHue { 0 };

	if(max == val.Red)
	{
		resultHue = 0 + ((val.Green - val.Blue) * 60) / (max - min);
	}

	if(max == val.Green)
	{
		resultHue = 120 + ((val.Blue - val.Red) * 60) / (max - min);
	}

	if(max == val.Blue)
	{
		resultHue = 240 + ((val.Red - val.Green) * 60) / (max - min);
	}
	
	return resultHue < 0 ? resultHue += 360 : resultHue;
}

unsigned short int calculateSaturation(const int min, const int max, const RGB & val)
{
	if(max == 0) return 0;

	return (max - min) * 100 / max;
}
