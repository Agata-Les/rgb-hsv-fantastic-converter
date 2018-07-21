#include "rgb_hsv_converter.h"
#include <cstdlib>
#include <cmath>

HSV convert_RGB_to_HSV(const RGB & RGBValues)
{
	HSV result {};

	result.Value = calculateValue(RGBValues.maximum);
	result.Hue = calculateHue(RGBValues);
	result.Saturation = calculateSaturation(RGBValues.minimum, RGBValues.maximum);

	return result;
}

RGB convert_HSV_to_RGB(const HSV & HSVValues)
{
	const float chroma = HSVValues.Value * HSVValues.Saturation;
	const float minimum = 100 * HSVValues.Value - chroma;

	float x = chroma * (1.0 - std::abs(std::fmod(HSVValues.Hue/60, 2.0) - 1.0));

	return {0, 0, 0};
}

float calculateValue(const unsigned short int max)
{
	return std::round((100.0 * max) / 255.0 * 10) / 10;
}

unsigned short int calculateHue(const RGB & val)
{
	if(val.minimum == val.maximum) return 0;

	float resultHue { 0 };

	if(val.maximum == val.Red)
	{
		resultHue = 0.0 + ((val.Green - val.Blue) * 60.0) / (val.maximum - val.minimum);
	}

	if(val.maximum == val.Green)
	{
		resultHue = 120.0 + ((val.Blue - val.Red) * 60.0) / (val.maximum - val.minimum);
	}

	if(val.maximum == val.Blue)
	{
		resultHue = 240.0 + ((val.Red - val.Green) * 60.0) / (val.maximum - val.minimum);
	}
	
	return resultHue < 0 ? std::round(resultHue += 360) : std::round(resultHue);
}

float calculateSaturation(const unsigned short int min, const unsigned short int max)
{
	if(max == 0) return 0.0;

	return std::round((max - min) * 100.0 / max * 10) / 10;
}
