#include "rgb.h"
#include <utility>
#include <algorithm>

unsigned short int RGB::calculateMin()
{
	return std::min(std::min(Red, Blue), Green);
}

unsigned short int RGB::calculateMax()
{
	return std::max(std::max(Red, Blue), Green);
}

unsigned short int RGB::getMin() const
{
	return minimum;
}

unsigned short int RGB::getMax() const
{
	return maximum;
}
