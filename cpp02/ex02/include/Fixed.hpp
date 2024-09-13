#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
public:
	//constructors
	Fixed();
	Fixed(const int value);
	Fixed(const float value);
	Fixed(const Fixed &other);

	//destructors
	~Fixed();

	//assignment operator
	Fixed &operator=(const Fixed &other);

	//comparison operators
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;

	//arithmetic operators
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

	//increment and decrement operators
    Fixed &operator++();    // Pre-increment
    Fixed &operator--();    // Pre-decrement
    Fixed operator++(int);  // Post-increment
    Fixed operator--(int);  // Post-decrement

	//getter and setter
	int getRawBits() const;
	void setRawBits(int const raw);

	//conversion functions
	float toFloat() const;
	int toInt() const;

	//min and max functions
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);

private:
	int _value;
	static const int _fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif