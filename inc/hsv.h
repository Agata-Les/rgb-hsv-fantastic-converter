#pragma once

struct HSV
{
	unsigned short int Hue;
	float Saturation;
	float Value;
};

inline bool operator ==(const HSV & lhs, const HSV & rhs)
{
	return lhs.Hue == rhs.Hue && lhs.Saturation == rhs.Saturation && lhs.Value == rhs.Value;
}

inline bool operator !=(const HSV & lhs, const HSV & rhs)
{
	return lhs.Hue != rhs.Hue || lhs.Saturation != rhs.Saturation || lhs.Value != rhs.Value;
}
