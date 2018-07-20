#include "rgb_hsv_converter.h"

HSV convert_RGB_to_HSV(const RGB & RGBValues)
{
	HSV result {};

	result.Value = calculateValue(RGBValues.getMax());
	result.Hue = calculateHue(RGBValues);
	result.Saturation = calculateSaturation(RGBValues.getMin(), RGBValues.getMax());

	return result;
}

unsigned short int calculateValue(const unsigned short int max)
{
	return (100 * max) / 255;
}

unsigned short int calculateHue(const RGB & val)
{
	const unsigned short int min = val.getMin();
	const unsigned short int max = val.getMax();

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

unsigned short int calculateSaturation(const unsigned short int min, const unsigned short int max)
{
	if(max == 0) return 0;

	return (max - min) * 100 / max;
}
