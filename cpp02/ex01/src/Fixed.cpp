#include "Fixed.hpp"

/************** constructors **************/

Fixed::Fixed() : _value(0) { std::cout << "Default constructor called\n"; }

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called\n";
    *this = other;
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called\n";
    _value = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called\n";
    _value = roundf(value * (1 << _fractionalBits));
}

/************** destructors ***************/

Fixed::~Fixed() { std::cout << "Destructor called\n"; }

/************** operators ****************/

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Assignment operator called\n";
    if (this != &other) {
        _value = other.getRawBits();
    }
    return *this;
}

/*********** member functions *************/

int Fixed::getRawBits() const {
    // std::cout << "getRawBits member function called\n";
    return _value;
}

void Fixed::setRawBits(const int raw) {
    // std::cout << "setRawBits member function called\n";
    _value = raw;
}

float Fixed::toFloat() const {
    return ((float)_value / (1 << _fractionalBits));
}

int Fixed::toInt() const { return _value >> _fractionalBits; }

/********** non-member functions **********/

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}
