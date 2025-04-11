#include "Fixed.hpp"

/************** constructors **************/

Fixed::Fixed() : _value(0) {
    // std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& other) {
    *this = other;

    // std::cout << "Copy constructor called\n";
}

Fixed::Fixed(const int value) {
    // std::cout << "Int constructor called\n";
    _value = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
    // std::cout << "Float constructor called\n";
    _value = roundf(value * (1 << _fractionalBits));
}

/************** destructors ***************/

Fixed::~Fixed() {
    // std::cout << "Destructor called\n";
}

/********** assignment operator ***********/

Fixed& Fixed::operator=(const Fixed& other) {
    // std::cout << "Assignment operator called\n";
    if (this != &other) {
        _value = other.getRawBits();
    }
    return *this;
}

/********** comparison operators **********/

bool Fixed::operator==(const Fixed& other) const {
    return (_value == other.getRawBits());
}

bool Fixed::operator!=(const Fixed& other) const {
    return (_value != other.getRawBits());
}

bool Fixed::operator>(const Fixed& other) const {
    return (_value > other.getRawBits());
}

bool Fixed::operator<(const Fixed& other) const {
    return (_value < other.getRawBits());
}

bool Fixed::operator>=(const Fixed& other) const {
    return (_value >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed& other) const {
    return (_value <= other.getRawBits());
}

/********** arithmetic operators **********/

Fixed Fixed::operator+(const Fixed& other) const {
    return (Fixed(toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed& other) const {
    return (Fixed(toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed& other) const {
    return (Fixed(toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed& other) const {
    if (other.toFloat() == 0.0f) {
        if (toFloat() > 0) {
            return (Fixed(INFINITY));
        } else if (toFloat() < 0) {
            return (Fixed(-INFINITY));
        } else {
            return (Fixed(0));  // 0 / 0 is undefined, but we can return (0)
        }
    }
    return (Fixed(toFloat() / other.toFloat()));
}

/*** increment and decrement operators ****/

Fixed& Fixed::operator++() {  // Pre-increment
    _value++;
    return *this;
}

Fixed& Fixed::operator--() {  // Pre-decrement
    _value--;
    return *this;
}

Fixed Fixed::operator++(int) {  // Post-increment
    Fixed temp(*this);
    operator++();
    return temp;
}

Fixed Fixed::operator--(int) {  // Post-decrement
    Fixed temp(*this);
    operator--();
    return temp;
}

/*********** getter and setter ************/

int Fixed::getRawBits() const {
    // std::cout << "getRawBits member function called\n";
    return _value;
}

void Fixed::setRawBits(const int raw) {
    // std::cout << "setRawBits member function called\n";
    _value = raw;
}

/********** conversion functions **********/

float Fixed::toFloat() const {
    return ((float)_value / (1 << _fractionalBits));
}

int Fixed::toInt() const { return _value >> _fractionalBits; }

/********** min and max functions **********/

Fixed& Fixed::min(Fixed& a, Fixed& b) { return a < b ? a : b; }

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return a < b ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) { return a > b ? a : b; }

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return a > b ? a : b;
}

/*********** insertion operator ***********/

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}
