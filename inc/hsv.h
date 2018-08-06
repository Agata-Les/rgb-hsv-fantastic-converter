#pragma once

struct HSV
{
	HSV(float Hue_, float Saturation_, float Value_) : Hue(Hue_),
													   Saturation(Saturation_),
													   Value(Value_)
	{
	}
	
	float Hue;
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
