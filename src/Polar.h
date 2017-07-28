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

    double angle;                       ///< vector angle from point
    const bool radians;                 ///< is vAngle in radians (true) or degrees (false)?
    const double minAngle = 0.0;        ///< used to check a new angle input
    const double maxDegrees = 360.0;    ///< used to check a new angle input
    const double maxRadians = 2.0;      ///< used to check a new angle input

    void setAngle(double a);
    double getAngle() { return angle; }
    double convertDegrees2Radians() { return (isDegrees()) ? getAngle() * M_PI/180.0 : getAngle(); };
    bool getRadians() { return radians; }
    string angleUnits() { return (isRadians()) ? "radians" : "degrees"; }
    string angleRange() { return (isRadians()) ? "[0.0 : 2.0]" : "[0.0 : 360.0]"; }

public:

    explicit Polar(bool r);
    Polar(double x, double y, double a, bool r);
    Polar(tuple<double, double, double> xya, bool r);

    void getVector(double *x, double *y, double *a);
    tuple<double, double, double> getVector();

    void setVector(double x, double y, double a);
    void setVector(tuple<double, double, double> xya);

    bool isDegrees() { return !getRadians(); }
    bool isRadians() { return getRadians(); }

    double cosAngle() { return cos(convertDegrees2Radians()); }
    double sinAngle() { return sin(convertDegrees2Radians()); }

    void print() override;
    void print(double x, double y, double a);

};

#endif //COORD_POLAR_H
