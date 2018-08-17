#pragma once

#include <ostream>

struct HSV
{
	HSV(float Hue_, float Saturation_, float Value_) : Hue(Hue_),
													   Saturation(Saturation_),
													   Value(Value_)
	{
	}

	bool operator ==(const HSV & rhs) const;
	bool operator !=(const HSV & rhs) const;
	friend std::ostream & operator <<(std::ostream & stream, const HSV & hsvColour);

	const float getHue() const;
	const float getSaturation() const;
	const float getValue() const;

private:
	float Hue;
	float Saturation;
	float Value;
};
