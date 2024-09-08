#ifndef LINE_HPP
#define LINE_HPP

#include "Point.hpp"

struct Line
{
	Line(Point const p1, Point const p2);

	Point _p1;
	Point _p2;

	float sideOfLine(Point const point) const;
};

#endif