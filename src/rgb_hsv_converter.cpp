#include "rgb_hsv_converter.h"

HSV convert_RGB_to_HSV(const RGB & RGBValues)
{
	HSV result {};

	result.Value = calculateValue(RGBValues.maximum);
	result.Hue = calculateHue(RGBValues);
	result.Saturation = calculateSaturation(RGBValues.minimum, RGBValues.maximum);

	return result;
}

unsigned short int calculateValue(const unsigned short int max)
{
	return (100 * max) / 255;
}

unsigned short int calculateHue(const RGB & val)
{
	if(val.minimum == val.maximum) return 0;

	int resultHue { 0 };

	if(val.maximum == val.Red)
	{
		resultHue = 0 + ((val.Green - val.Blue) * 60) / (val.maximum - val.minimum);
	}

	if(val.maximum == val.Green)
	{
		resultHue = 120 + ((val.Blue - val.Red) * 60) / (val.maximum - val.minimum);
	}

	if(val.maximum == val.Blue)
	{
		resultHue = 240 + ((val.Red - val.Green) * 60) / (val.maximum - val.minimum);
	}
	
	return resultHue < 0 ? resultHue += 360 : resultHue;
}

unsigned short int calculateSaturation(const unsigned short int min, const unsigned short int max)
{
	if(max == 0) return 0;

	return (max - min) * 100 / max;
}
