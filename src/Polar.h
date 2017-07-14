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

    float Angle;  // vector angle from point
    bool Radians; // is Angle in radians or degrees? default: false (degrees)

    float getAngle() { return Polar::Angle; }
    void setAngle(float angle) {Polar::Angle = angle;}

public:

    Polar(bool radians = false);
    Polar(float x, float y, float angle, bool radians = false);
    Polar(std::tuple<float, float, float> xya, bool radians = false);

    float angle() { return Polar::getAngle(); };
    void vector(float *x, float *y, float *angle);
    std::tuple<float, float, float> vector();

    void angle(float angle) { Polar::setAngle(angle); };
    void vector(float x, float y, float angle);
    void vector(std::tuple<float, float, float> xya);

    bool isDegrees() { return !Polar::Radians; };
    bool isRadians() { return Polar::Radians; };

    float cosAngle();
    float sinAngle();

    void print();

};

#endif //COORD_POLAR_H
