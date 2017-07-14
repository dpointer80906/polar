// Two dimensional x,y,angle vector object services.
//
// David Pointer <david.b.pointer@gmail.com>
//
#ifndef COORD_POLAR_H
#define COORD_POLAR_H
#include <cmath>
#include <tuple>
#include "Point.h"

class Polar : public Point {

    double Angle;  // vector angle from point
    bool Radians; // is Angle in radians or degrees? default: false (degrees)

    double getAngle() { return Polar::Angle; }
    void setAngle(double angle) {Polar::Angle = angle;}

public:

    Polar(bool radians = false);
    Polar(double x, double y, double angle, bool radians = false);
    Polar(std::tuple<double, double, double> xya, bool radians = false);

    double angle() { return Polar::getAngle(); };
    void vector(double *x, double *y, double *angle);
    std::tuple<double, double, double> vector();

    void angle(double angle) { Polar::setAngle(angle); };
    void vector(double x, double y, double angle);
    void vector(std::tuple<double, double, double> xya);

    bool isDegrees() { return !Polar::Radians; };
    bool isRadians() { return Polar::Radians; };

    double cosAngle();
    double sinAngle();

    void print();

};

#endif //COORD_POLAR_H
