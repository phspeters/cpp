#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class Fixed {
   public:
    // constructors
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed& other);

    // destructors
    ~Fixed();

    // operators
    Fixed& operator=(const Fixed& other);

    // member functions
    int getRawBits() const;
    void setRawBits(const int raw);
    float toFloat() const;
    int toInt() const;

   private:
    int _value;
    static const int _fractionalBits = 8;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif