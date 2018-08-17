#include "rgb.h"
#include <algorithm>

bool RGB::operator ==(const RGB & rhs) const
{
	return this->Red == rhs.Red && this->Green == rhs.Green && this->Blue == rhs.Blue;
}

bool RGB::operator !=(const RGB & rhs) const
{
	return this->Red != rhs.Red || this->Green != rhs.Green || this->Blue != rhs.Blue;
}

std::ostream & operator <<(std::ostream & stream, const RGB & rgbColour)
{
	return stream<<"{ "<<rgbColour.Red<<", "<<rgbColour.Green<<", "<<rgbColour.Blue<<" }";
}

unsigned short int RGB::calculateMin()
{
	return std::min(std::min(Red, Blue), Green);
}

unsigned short int RGB::calculateMax()
{
	return std::max(std::max(Red, Blue), Green);
}

const unsigned short int RGB::getRed() const
{
	return Red;
}

const unsigned short int RGB::getGreen() const
{
	return Green;
}

const unsigned short int RGB::getBlue() const
{
	return Blue;
}

const unsigned short int RGB::getMax() const
{
	return maximum;
}

const unsigned short int RGB::getMin() const
{
	return minimum;
}
