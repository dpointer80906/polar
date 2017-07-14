#include <iostream>
#include "Point.h"

// default constructor
Point::Point() {
    Point::setXY(std::make_tuple(0.0, 0.0));
}

// separate x,y values constructor
Point::Point(float x, float y) {
    Point::setXY(std::make_tuple(x, y));
}

// x,y tuple constructor
Point::Point(std::tuple<float, float> xy) {
    Point::setXY(xy);
}

// tuple x,y getter
std::tuple<float, float> Point::xy() {
    return Point::getXY();
}

// separate x,y values getter
void Point::xy(float *x, float *y) {
    *x = Point::x();
    *y = Point::y();
}

// x getter
float Point::x() {
    return std::get<0>(Point::getXY());
}

// y getter
float Point::y() {
    return std::get<1>(Point::getXY());
}

// tuple x,y setter
void Point::xy(std::tuple<float, float> xy) {
    Point::setXY(xy);
}

// separate x,y value setter
void Point::xy(float x, float y) {
    Point::x(x);
    Point::y(y);
}

// x setter
void Point::x(float x) {
    std::tuple<float, float> xy = Point::xy();
    std::get<0>(xy) = x;
    Point::xy(xy);
}

// y setter
void Point::y(float y) {
    std::tuple<float, float> xy = Point::xy();
    std::get<1>(xy) = y;
    Point::xy(xy);
}

void Point::print() {
    std::cout << this->x() << " " << this->y() << std::endl;
}
