#include "Point.h"

// default constructor
Point::Point() {
    Point::xy(std::make_tuple(0.0, 0.0));
}

// separate x,y values constructor
Point::Point(float x, float y) {
    Point::xy(std::make_tuple(x, y));
}

// x,y tuple constructor
Point::Point(std::tuple<float, float> xy) {
    Point::xy(xy);
}

// x,y tuple getter
std::tuple<float, float> Point::xy() {
    return Point::XY;
}

// separate x,y values getter
void Point::xy(float *x, float *y) {
    *x = Point::x();
    *y = Point::y();
}

// x getter
float Point::x() {
    return std::get<0>(Point::XY);
}

// y getter
float Point::y() {
    return std::get<1>(Point::XY);
}

// x,y tuple setter
void Point::xy(std::tuple<float, float> xy) {
    Point::XY = xy;
}

// separate x,y value setter
void Point::xy(float x, float y) {
    Point::x(x);
    Point::y(y);
}

// x setter
void Point::x(float x) {
    std::get<0>(Point::XY) = x;
}

// y setter
void Point::y(float y) {
    std::get<1>(Point::XY) = y;
}
