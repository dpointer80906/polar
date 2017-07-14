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

    std::tuple<float, float> XY;  // x-axis and y-axis coordinates, only accessed directly by private getter/setter

    std::tuple<float, float> getXY() { return Point::XY; }
    void setXY(std::tuple<float, float> xy) { Point::XY = xy; }

public:

    Point();
    Point(float x, float y);
    Point(std::tuple<float, float> xy);

    std::tuple<float, float> xy();
    void xy(float *x, float *y);
    float x();
    float y();

    void xy(std::tuple<float, float> xy);
    void xy(float x, float y);
    void x(float x);
    void y(float y);

    virtual void print();
};

#endif //COORD_POINT_H
