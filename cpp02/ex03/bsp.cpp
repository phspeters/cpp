#include "Point.hpp"
#include "Line.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Line ab(a, b);
    Line bc(b, c);
    Line ca(c, a);
    
    double side1 = ab.sideOfLine(point);
    double side2 = bc.sideOfLine(point);
    double side3 = ca.sideOfLine(point);
    
    return (side1 >= 0 && side2 >= 0 && side3 >= 0) || 
           (side1 <= 0 && side2 <= 0 && side3 <= 0);
}
