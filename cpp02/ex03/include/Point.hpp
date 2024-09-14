#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include "Fixed.hpp"

class Point
{
public:
	//constructors
	Point();
	Point(const Point &other);
	Point(const float x, const float y);

	//destructors
	~Point();

	//assignment operator
	Point &operator=(const Point &other);

	//getters
	float getX() const;
	float getY() const;

	//member functions
	double sideOfLine(const Point a, const Point b) const;

private:
	const Fixed _x;
	const Fixed _y;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif