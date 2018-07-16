#pragma once

#include <vector>

struct RGB {
	unsigned short int Red;
	unsigned short int Green;
	unsigned short int Blue;
};

struct HSV {
	unsigned int Hue;
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
