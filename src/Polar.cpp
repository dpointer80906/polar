#include <iostream>
#include "Polar.h"

// default constructor
Polar::Polar(bool radians /* def false */ ) {
    Polar::angle(0.0);
    Polar::Radians = radians;
}

// distinct x,y,angle constructor
Polar::Polar(double x, double y, double angle, bool radians /* def false */ ) {
    Polar::vector(x, y, angle);
    Polar::Radians = radians;
}

// tuple constructor
Polar::Polar(std::tuple<double, double, double> xya, bool radians /* def false */ ) {
    Polar::vector(xya);
    Polar::Radians = radians;
}

// distinct x,y,angle getter
void Polar::vector(double *x, double *y, double *angle) {
    *x = Polar::x();
    *y = Polar::y();
    *angle = Polar::angle();
}

// tuple s,y,angle getter
std::tuple<double, double, double> Polar::vector() {
    std::tuple<double, double, double> xya = std::make_tuple(Polar::x(), Polar::y(), Polar::angle());
    return xya;
}

// x,y,angle setter
void Polar::vector(double x, double y, double angle) {
    Polar::xy(x, y);
    Polar::angle(angle);
}

// tuple s,y,angle setter
void Polar::vector(std::tuple<double, double, double> xya) {
    double x = std::get<0>(xya);
    double y = std::get<1>(xya);
    double angle = std::get<2>(xya);
    Polar::xy(x, y);
    Polar::angle(angle);
}

double Polar::cosAngle() {
    double angle = (this->isDegrees()) ? this->getAngle() * 180.0/M_PI : this->getAngle();
    double cos_angle = cos(angle);
    return cos_angle;
}

double Polar::sinAngle() {
    double angle = (this->isDegrees()) ? this->getAngle() * 180.0/M_PI : this->getAngle();
    double sin_angle = sin(angle);
    return sin_angle;
}

void Polar::print() {
    std::cout << this->x() << " " << this->y() << " " << this->angle() << std::endl;
}
