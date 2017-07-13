// Two dimensional x,y,angle vector object services.
//
// David Pointer <david.b.pointer@gmail.com>
//
#ifndef COORD_POLAR_H
#define COORD_POLAR_H
#include <tuple>
#include "Point.h"

class Polar {

    Point point;  // x,y coordinates of this vector
    float Angle;  // vector angle from point
    bool radians; // is Angle in radians or degrees? default: false (degrees)

public:

    Polar(bool radians = false);
    Polar(float x, float y, float angle, bool radians = false);
    Polar(std::tuple<float, float, float> xya, bool radians = false);

    float angle() { return Polar::Angle; };
    void vector(float *x, float *y, float *angle);
    std::tuple<float, float, float> vector();

    void angle(float angle) { Polar::Angle = angle; };
    void vector(float x, float y, float angle);
    void vector(std::tuple<float, float, float> xya);

    bool isDegrees() { return !Polar::radians; };
    bool iRadians() { return Polar::radians; };

};

#endif //COORD_POLAR_H
