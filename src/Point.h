// Two dimensional x,y coordinate object services.
//
// David Pointer <david.b.pointer@gmail.com>
//
#ifndef COORD_POINT_H
#define COORD_POINT_H
#include <tuple>

// In this class "x" refers to a horizontal axis coordinate and "y"
// to a vertical axis coordinate.
class Point {

    std::tuple<double, double> XY;  // x-axis and y-axis coordinates, only accessed directly by private getter/setter

    std::tuple<double, double> getXY() { return Point::XY; }
    void setXY(std::tuple<double, double> xy) { Point::XY = xy; }

public:

    Point();
    Point(double x, double y);
    Point(std::tuple<double, double> xy);

    std::tuple<double, double> xy();
    void xy(double *x, double *y);
    double x();
    double y();

    void xy(std::tuple<double, double> xy);
    void xy(double x, double y);
    void x(double x);
    void y(double y);

    virtual void print();
};

#endif //COORD_POINT_H
