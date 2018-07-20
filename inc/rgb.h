#pragma once

struct RGB
{
	RGB(unsigned short int Red_, unsigned short int Green_, unsigned short int Blue_) : Red(Red_), Green(Green_), Blue(Blue_)
	{
		minimum = calculateMin();
		maximum = calculateMax();
	}

	unsigned short int Red;
	unsigned short int Green;
	unsigned short int Blue;

	unsigned short int getMin() const;
	unsigned short int getMax() const;

private:
	unsigned short int minimum;
	unsigned short int maximum;

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
