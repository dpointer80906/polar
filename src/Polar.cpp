#include <iostream>
#include "Polar.h"

// default constructor
Polar::Polar(bool radians /* def false */ ) {
    Polar::angle(0.0);
    Polar::Radians = radians;
}

// distinct x,y,angle constructor
Polar::Polar(float x, float y, float angle, bool radians /* def false */ ) {
    Polar::vector(x, y, angle);
    Polar::Radians = radians;
}

// tuple constructor
Polar::Polar(std::tuple<float, float, float> xya, bool radians /* def false */ ) {
    Polar::vector(xya);
    Polar::Radians = radians;
}

// distinct x,y,angle getter
void Polar::vector(float *x, float *y, float *angle) {
    *x = Polar::x();
    *y = Polar::y();
    *angle = Polar::angle();
}

// tuple s,y,angle getter
std::tuple<float, float, float> Polar::vector() {
    std::tuple<float, float, float> xya = std::make_tuple(Polar::x(), Polar::y(), Polar::angle());
    return xya;
}

// x,y,angle setter
void Polar::vector(float x, float y, float angle) {
    Polar::xy(x, y);
    Polar::angle(angle);
}

// tuple s,y,angle setter
void Polar::vector(std::tuple<float, float, float> xya) {
    float x = std::get<0>(xya);
    float y = std::get<1>(xya);
    float angle = std::get<2>(xya);
    Polar::xy(x, y);
    Polar::angle(angle);
}

float Polar::cosAngle() {
    double angle = (this->isDegrees()) ? this->getAngle() * 180.0/M_PI : this->getAngle();
    double cos_angle = cos(angle);
    return (float)cos_angle;
}

float Polar::sinAngle() {
    double angle = (this->isDegrees()) ? this->getAngle() * 180.0/M_PI : this->getAngle();
    double sin_angle = sin(angle);
    return (float)sin_angle;
}

void Polar::print() {
    std::cout << this->x() << " " << this->y() << " " << this->angle() << std::endl;
}
