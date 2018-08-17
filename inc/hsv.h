#pragma once

struct HSV
{
	HSV(float Hue_, float Saturation_, float Value_) : Hue(Hue_),
													   Saturation(Saturation_),
													   Value(Value_)
	{
	}

	bool operator ==(const HSV & rhs) const;
	bool operator !=(const HSV & rhs) const;

	const float getHue() const;
	const float getSaturation() const;
	const float getValue() const;

private:
	float Hue;
	float Saturation;
	float Value;
};
