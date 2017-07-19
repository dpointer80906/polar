#ifndef COORD_POINT_H
#define COORD_POINT_H
#include <iostream>
#include <tuple>

using namespace std;

/*!
 * @class Point
 *
 * Two dimensional x,y coordinate object services.
 *
 * In this class "x" refers to a horizontal axis coordinate and "y"
 * to a vertical axis coordinate.
 */
class Point {

    tuple<double, double> coord;       ///< point x-axis, y-axis coordinates

    void setCoord(tuple<double, double> xy);

public:

    Point();
    Point(double x, double y);
    explicit Point(tuple<double, double> xy);

    tuple<double, double> getXY();
    void getXY(double *x, double *y);
    double getX();
    double getY();

    void setXY(tuple<double, double> xy);
    void setXY(double x, double y);
    void setX(double x);
    void setY(double y);

    virtual void print();
    void print(double x, double y);

};

#endif //COORD_POINT_H
