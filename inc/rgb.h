#pragma once

#include <ostream>

struct RGB
{
	RGB(unsigned short int Red_, unsigned short int Green_, unsigned short int Blue_) : Red(Red_), 
																						Green(Green_), 
																						Blue(Blue_), 
																						minimum(calculateMin()),
																						maximum(calculateMax())
	{		
	}

	bool operator ==(const RGB & rhs) const;
	bool operator !=(const RGB & rhs) const;
	friend std::ostream & operator <<(std::ostream & stream, const RGB & rgbColour);

	const unsigned short int getRed() const;
	const unsigned short int getGreen() const;
	const unsigned short int getBlue() const;

	const unsigned short int getMax() const;
	const unsigned short int getMin() const;

protected:
	const unsigned short int Red;
	const unsigned short int Green;
	const unsigned short int Blue;

	const unsigned short int minimum;
	const unsigned short int maximum;

	unsigned short int calculateMin();
	unsigned short int calculateMax();
};
