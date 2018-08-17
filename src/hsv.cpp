#include "hsv.h"

bool HSV::operator ==(const HSV & rhs) const
{
	return this->Hue == rhs.Hue && this->Saturation == rhs.Saturation && this->Value == rhs.Value;
}

bool HSV::operator !=(const HSV & rhs) const
{
	return this->Hue != rhs.Hue || this->Saturation != rhs.Saturation || this->Value != rhs.Value;
}

const float HSV::getHue() const
{
	return Hue;
}

const float HSV::getSaturation() const
{
	return Saturation;
}

const float HSV::getValue() const
{
	return Value;
}
