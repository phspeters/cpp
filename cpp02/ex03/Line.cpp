#include "Line.hpp"
#include "Point.hpp"
#include "Fixed.hpp"

Line::Line(Point const a, Point const b) : _p1(a), _p2(b) {}

float Line::sideOfLine(Point const point) const
{
	float x1 = _p1.getX();
	float y1 = _p1.getY();
	float x2 = _p2.getX();
	float y2 = _p2.getY();
	float x = point.getX();
	float y = point.getY();

	return ((x - x1) * (y2 - y1) - (y - y1) * (x2 - x1));
}