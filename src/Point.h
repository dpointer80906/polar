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

    std::tuple<float, float> XY;  // x-axis and y-axis coordinates

public:

    Point();
    Point(float, float);
    Point(std::tuple<float, float>);

    std::tuple<float, float> xy();
    void xy(float *, float *);
    float x();
    float y();

    void xy(std::tuple<float, float>);
    void xy(float, float);
    void x(float);
    void y(float);
};

#endif //COORD_POINT_H
