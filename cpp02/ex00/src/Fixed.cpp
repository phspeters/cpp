#include "Fixed.hpp"

/************** constructors **************/

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	*this = other;
	
	std::cout << "Copy constructor called" << std::endl;
}

/************** destructors ***************/

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/************** operators ****************/

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Assignment operator called" << std::endl;
	if (this != &other)
		_value = other.getRawBits();
	return (*this);
}

/*********** member functions *************/

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}
