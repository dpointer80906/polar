#ifndef COORD_POLAR_H
#define COORD_POLAR_H
#include <iostream>
#include <cmath>
#include <tuple>
#include "Point.h"

using namespace std;

/*!
 * @class Polar
 *
 * Two dimensional x,y,angle polar mathematical vector coordinate object services.
 */
class Polar : public Point {

    double vAngle;      ///< vector angle from point
    bool aRadians;      ///< is Angle in radians or degrees? default: false (degrees)

    double getAngle() { return vAngle; }        ///< private getter
    void setAngle(double a) { vAngle = a; }     ///< private setter
    bool getRadians() { return aRadians; }      ///< private getter
    void setRadians(bool r) { aRadians = r; }   ///< private setter

public:

    Polar(bool radians = false);
    Polar(double x, double y, double a, bool r = false);
    Polar(tuple<double, double, double> xya, bool r = false);

    double angle();
    void vector(double *x, double *y, double *a);
    tuple<double, double, double> vector();

    void angle(double a);
    void vector(double x, double y, double a);
    void vector(tuple<double, double, double> xya);

    bool isDegrees();
    bool isRadians();

    double cosAngle();
    double sinAngle();

    void print();
    void print(double x, double y, double a);

};

#endif //COORD_POLAR_H
