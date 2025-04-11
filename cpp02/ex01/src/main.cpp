#include "Fixed.hpp"

int main() {
    std::cout << "DEFAULT CONSTRUCTOR:\n";
    Fixed a;
    std::cout << '\n';

    std::cout << "INT CONSTRUCTOR:\n";
    const Fixed b(10);
    std::cout << '\n';

    std::cout << "FLOAT CONSTRUCTOR:\n";
    const Fixed c(42.42424242424242f);
    std::cout << '\n';

    std::cout << "COPY CONSTRUCTOR:\n";
    const Fixed d(b);
    std::cout << '\n';

    std::cout << "ASSIGNMENT OPERATOR:\n";
    a = Fixed(1234.4321f);
    std::cout << '\n';

    std::cout << "PRINTING VALUES AS RAW BITS:\n";
    std::cout << "a is " << a.getRawBits() << '\n';
    std::cout << "b is " << b.getRawBits() << '\n';
    std::cout << "c is " << c.getRawBits() << '\n';
    std::cout << "d is " << d.getRawBits() << '\n';
    std::cout << '\n';

    std::cout << "PRINTING VALUES AS FIXED POINT:\n";
    std::cout << "a is " << a << '\n';
    std::cout << "b is " << b << '\n';
    std::cout << "c is " << c << '\n';
    std::cout << "d is " << d << '\n';
    std::cout << '\n';

    std::cout << "PRINTING VALUES AS INTEGER:\n";
    std::cout << "a is " << a.toInt() << '\n';
    std::cout << "b is " << b.toInt() << '\n';
    std::cout << "c is " << c.toInt() << '\n';
    std::cout << "d is " << d.toInt() << '\n';
    std::cout << '\n';

    std::cout << "DESTRUCTORS:\n";
    return 0;
}