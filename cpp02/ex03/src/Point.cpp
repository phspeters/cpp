#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const Point &other) : _x(other._x), _y(other._y) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::~Point() {}

Point &Point::operator=(const Point &other)
{
	(void)other;
	return (*this);
}

float Point::getX() const
{
	return (_x.toFloat());
}

float Point::getY() const
{
	return (_y.toFloat());
}

/**
 * @brief Calculate the side of a point relative to the line (a->b) by using the cross product of 2D vectors.
 * The cross product of two 2D vectors (a,b) and (c,d) is defined as: (a,b) × (c,d) = a.d - b.c
 * and the result is a scalar value, which is positive if the angle between the two vectors is
 * positive (counter-clockwise) and negative if the angle between the two vectors is negative (clockwise).
 * Our line is defined by two points 'a' and 'b', and we want to know on which side of the line a point 'p'
 * is located. We can use the cross product of the vectors (a,p) and (a,b) to determine this.
 * The formula for it is (b.x - a.x) * (p.y - a.y) - (b.y - a.y) * (p.x - a.x) where x and y represent the
 * coordinates of the points.
 * 
 * @param this The point to check.
 * @param a The starting point of the line.
 * @param b The ending point of the line.
 * @return signed double. If the result is positive, the point is on the "left side" of the line, if it
 * is negative, the point is on the "right side" of the line.
 */
double Point::sideOfLine(const Point a, const Point b) const
{
	float ax = a.getX();
	float ay = a.getY();
	float bx = b.getX();
	float by = b.getY();
	float px = getX();
	float py = getY();

	return ((bx - ax) * (py - ay) - (by - ay) * (px - ax));
}
