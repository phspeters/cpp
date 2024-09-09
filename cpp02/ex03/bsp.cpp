#include "Point.hpp"
#include "Line.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Line ab(a, b);
    Line bc(b, c);
    Line ca(c, a);
    
    double sideAB = ab.sideOfLine(point);
    double sideBC = bc.sideOfLine(point);
    double sideCA = ca.sideOfLine(point);
    
    return (sideAB >= 0 && sideBC >= 0 && sideCA >= 0) || 
           (sideAB <= 0 && sideBC <= 0 && sideCA <= 0);
}
