#include "rgb_hsv_converter.h"
#include <utility>

HSV convert_RGB_to_HSV(const RGB & RGBValues)
{
	HSV result {};

	const int& minimalValueOfColour = std::min(std::min(RGBValues.Red, RGBValues.Blue), RGBValues.Green);
	const int& maximalValueOfColour = std::max(std::max(RGBValues.Red, RGBValues.Blue), RGBValues.Green);

	result.Value = (100 * maximalValueOfColour) / 255;

	if(maximalValueOfColour == 0) result.Saturation = 0;
	else result.Saturation = (maximalValueOfColour - minimalValueOfColour) * 100 / maximalValueOfColour;

	if(minimalValueOfColour == maximalValueOfColour) result.Hue = 0;

	else if(maximalValueOfColour == RGBValues.Red)
	{
		result.Hue = 0 + ((RGBValues.Green - RGBValues.Blue) * 60) / (maximalValueOfColour - minimalValueOfColour);
	}

	else if(maximalValueOfColour == RGBValues.Green)
	{
		result.Hue = 120 + ((RGBValues.Blue - RGBValues.Red) * 60) / (maximalValueOfColour - minimalValueOfColour);
	}

	else if(maximalValueOfColour == RGBValues.Blue)
	{
		result.Hue = 240 + ((RGBValues.Red - RGBValues.Green) * 60) / (maximalValueOfColour - minimalValueOfColour);
	}

	if(result.Hue < 0) result.Hue += 360;

	return result;
}
