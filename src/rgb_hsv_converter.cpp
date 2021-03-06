#include "rgb_hsv_converter.h"
#include <cstdlib>
#include <cmath>
#include <cassert>

inline bool isInRange(float value, int min, int max)
{
	return min <= value && value < max;
}

HSV convert_RGB_to_HSV(const RGB & RGBValues)
{
	float value = calculateValue(RGBValues.getMax());
	float hue = calculateHue(RGBValues);
	float saturation = calculateSaturation(RGBValues.getMin(), RGBValues.getMax());

	return { hue, saturation, value };
}

RGB convert_HSV_to_RGB(const HSV & HSVValues)
{
	assert(HSVValues.getHue() <= 360);

	const float chroma = ( HSVValues.getValue() / 100.0 ) * ( HSVValues.getSaturation() / 100.0 );
	const float min = HSVValues.getValue() / 100.0 - chroma;
	const float intermed = chroma * (1.0 - std::fabs(std::fmod(HSVValues.getHue() / 60.0, 2.0) - 1.0));

	const unsigned int cm = std::round((chroma + min) * 255);
	const unsigned int xm = std::round((intermed + min) * 255);
	const unsigned int mi = std::round(min * 255);

	if(isInRange(HSVValues.getHue(), 0, 60)) return RGB(cm, xm, mi);
	if(isInRange(HSVValues.getHue(), 60, 120)) return RGB(xm, cm, mi);
	if(isInRange(HSVValues.getHue(), 120, 180)) return RGB(mi, cm, xm);
	if(isInRange(HSVValues.getHue(), 180, 240)) return RGB(mi, xm, cm);
	if(isInRange(HSVValues.getHue(), 240, 300)) return RGB(xm, mi, cm);
	if(isInRange(HSVValues.getHue(), 300, 360)) return RGB(cm, mi, xm);

	return RGB(mi, mi, mi);
}

float calculateValue(const unsigned short int max)
{
	return std::round((100.0 * max) / 255.0 * 10.0) / 10.0;
}

unsigned short int calculateHue(const RGB & val)
{
	if(val.getMin() == val.getMax()) return 0;

	float resultHue { 0.0 };

	if(val.getMax() == val.getRed())
	{
		resultHue = 0.0 + ((val.getGreen() - val.getBlue()) * 60.0) / (val.getMax() - val.getMin());
	}

	if(val.getMax() == val.getGreen())
	{
		resultHue = 120.0 + ((val.getBlue() - val.getRed()) * 60.0) / (val.getMax() - val.getMin());
	}

	if(val.getMax() == val.getBlue())
	{
		resultHue = 240.0 + ((val.getRed() - val.getGreen()) * 60.0) / (val.getMax() - val.getMin());
	}
	
	return resultHue < 0 ? std::round(resultHue += 360.0) : std::round(resultHue);
}

float calculateSaturation(const unsigned short int min, const unsigned short int max)
{
	if(max == 0) return 0.0;

	return std::round((max - min) * 100.0 / max * 10.0) / 10.0;
}
