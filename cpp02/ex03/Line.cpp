#include "Line.hpp"
#include "Point.hpp"
#include "Fixed.hpp"

Line::Line(Point const a, Point const b) : _p1(a), _p2(b) {}

/**
 * @brief Calculate the side of a point relative to the line by using the cross product of 2D vectors.
 * The cross product of two 2D vectors (a,b) and (c,d) is defined as: (a,b) × (c,d) = a.d - b.c
 * and the result is a scalar value, which is positive if the angle between the two vectors is
 * positive (counter-clockwise) and negative if the angle between the two vectors is negative (clockwise).
 * Our line is defined by two points p1 and p2, and we want to know on which side of the line a point p
 * is located. We can use the cross product of the vectors (p1,p) and (p1,p2) to determine this.
 * The formula for it is (x2 - x1) * (y - y1) - (y2 - y1) * (x - x1).
 * 
 * @param this The line to check.
 * @param point The point we want to check relative to the line.
 * @return signed float. If the result is positive, the point is on the "left side" of the line, if it
 * is negative, the point is on the "right side" of the line. 
 */
float Line::sideOfLine(Point const point) const
{
	float x1 = _p1.getX();
	float y1 = _p1.getY();
	float x2 = _p2.getX();
	float y2 = _p2.getY();
	float x = point.getX();
	float y = point.getY();

	return ((x2 - x1) * (y - y1) - (y2 - y1) * (x - x1));
}
