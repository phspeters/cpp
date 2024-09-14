#include "Point.hpp"

/**
 * @brief Checks if a point is inside a triangle by using the cross product vectors.
 * First it checks the vector ab with the vector ap, then bc with bp and ca with cp.
 * (a,b) x (a,point) = (b-a) x (point-a)
 * (b,c) x (b,point) = (c-b) x (point-b)
 * (c,a) x (c,point) = (a-c) x (point-c)
 * If the cross product is positive, the point is on the "left side" of the vector, if
 * it is negative, it is on the "right side".
 * If all the cross products are positive or negative, the point is inside the triangle.
 * 
 * @param a First point of the triangle
 * @param b Second point of the triangle
 * @param c Third point of the triangle
 * @param point Point to check if it is inside the triangle
 * @return true If the point is inside the triangle
 * @return false If the point is outside the triangle
 */
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    double sideAB = point.sideOfLine(a,b);
    double sideBC = point.sideOfLine(b,c);
    double sideCA = point.sideOfLine(c,a);
    
    return (sideAB >= 0 && sideBC >= 0 && sideCA >= 0) || 
           (sideAB <= 0 && sideBC <= 0 && sideCA <= 0);
}
