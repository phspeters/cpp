#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
public:
	//constructors
	Fixed();
	Fixed(const Fixed &other);

	//destructors
	~Fixed();

	//operators
	Fixed &operator=(const Fixed &other);

	//functions
	int getRawBits() const;
	void setRawBits(int const raw);

private:
	int _value;
	static const int _fractionalBits = 8;
};

#endif