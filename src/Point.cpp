#include <iostream>
#include "Point.h"

// default constructor
Point::Point() {
    Point::setXY(std::make_tuple(0.0, 0.0));
}

// separate x,y values constructor
Point::Point(double x, double y) {
    Point::setXY(std::make_tuple(x, y));
}

// x,y tuple constructor
Point::Point(std::tuple<double, double> xy) {
    Point::setXY(xy);
}

// tuple x,y getter
std::tuple<double, double> Point::xy() {
    return Point::getXY();
}

// separate x,y values getter
void Point::xy(double *x, double *y) {
    *x = Point::x();
    *y = Point::y();
}

// x getter
double Point::x() {
    return std::get<0>(Point::getXY());
}

// y getter
double Point::y() {
    return std::get<1>(Point::getXY());
}

// tuple x,y setter
void Point::xy(std::tuple<double, double> xy) {
    Point::setXY(xy);
}

// separate x,y value setter
void Point::xy(double x, double y) {
    Point::x(x);
    Point::y(y);
}

// x setter
void Point::x(double x) {
    std::tuple<double, double> xy = Point::xy();
    std::get<0>(xy) = x;
    Point::xy(xy);
}

// y setter
void Point::y(double y) {
    std::tuple<double, double> xy = Point::xy();
    std::get<1>(xy) = y;
    Point::xy(xy);
}

void Point::print() {
    std::cout << this->x() << " " << this->y() << std::endl;
}
