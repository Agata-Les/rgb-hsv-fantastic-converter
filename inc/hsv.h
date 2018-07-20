#pragma once

struct HSV
{
	unsigned short int Hue;
	unsigned short int Saturation;
	unsigned short int Value;
};

inline bool operator ==(const HSV & lhs, const HSV & rhs)
{
	return lhs.Hue == rhs.Hue && lhs.Saturation == rhs.Saturation && lhs.Value == rhs.Value;
}

inline bool operator !=(const HSV & lhs, const HSV & rhs)
{
	return lhs.Hue != rhs.Hue || lhs.Saturation != rhs.Saturation || lhs.Value != rhs.Value;
}
