#pragma once

struct RGB
{
	RGB(unsigned short int Red_, unsigned short int Green_, unsigned short int Blue_) : Red(Red_), 
																						Green(Green_), 
																						Blue(Blue_), 
																						minimum(calculateMin()),
																						maximum(calculateMax())
	{		
	}

	const unsigned short int Red;
	const unsigned short int Green;
	const unsigned short int Blue;

	const unsigned short int minimum;
	const unsigned short int maximum;

private:
	unsigned short int calculateMin();
	unsigned short int calculateMax();
};

inline bool operator ==(const RGB & lhs, const RGB & rhs)
{
	return lhs.Red == rhs.Red && lhs.Green == rhs.Green && lhs.Blue == rhs.Blue;
}

inline bool operator !=(const RGB & lhs, const RGB & rhs)
{
	return lhs.Red != rhs.Red || lhs.Green != rhs.Green || lhs.Blue != rhs.Blue;
}
