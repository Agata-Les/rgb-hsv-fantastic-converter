#pragma once

#include <vector>

struct RGB
{
	RGB(unsigned short int Red_, unsigned short int Green_, unsigned short int Blue_) : Red(Red_), Green(Green_), Blue(Blue_)
	{
		minimum = calculateMin();
		maximum = calculateMax();
	}

	unsigned short int Red;
	unsigned short int Green;
	unsigned short int Blue;

	unsigned short int getMin() const;
	unsigned short int getMax() const;

private:
	unsigned short int minimum;
	unsigned short int maximum;

	unsigned short int calculateMin();
	unsigned short int calculateMax();
};

struct HSV
{
	unsigned short int Hue;
	unsigned short int Saturation;
	unsigned short int Value;
};

inline bool operator ==(const RGB & lhs, const RGB & rhs)
{
	return lhs.Red == rhs.Red && lhs.Green == rhs.Green && lhs.Blue == rhs.Blue;
}

inline bool operator ==(const HSV & lhs, const HSV & rhs)
{
	return lhs.Hue == rhs.Hue && lhs.Saturation == rhs.Saturation && lhs.Value == rhs.Value;
}

HSV convert_RGB_to_HSV(const RGB & RGBValues);
unsigned short int calculateValue(const unsigned short int max);
unsigned short int calculateHue(const RGB & val);
unsigned short int calculateSaturation(const unsigned short int min, const unsigned short int max);
