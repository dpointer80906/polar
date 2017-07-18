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

    tuple<double, double> pxy;       ///< point x-axis and y-axis coordinates

    tuple<double, double> getXY() { return pxy; }         ///< private getter
    void setXY(tuple<double, double> xy) { pxy = xy; }    ///< private setter

public:

    Point();
    Point(double x, double y);
    Point(tuple<double, double> xy);

    tuple<double, double> xy();
    void xy(double *x, double *y);
    double x();
    double y();

    void xy(tuple<double, double> xy);
    void xy(double x, double y);
    void x(double x);
    void y(double y);

    virtual void print();
    virtual void print(double x, double y);

};

#endif //COORD_POINT_H
