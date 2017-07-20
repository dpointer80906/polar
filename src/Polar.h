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

    double angle;      ///< vector angle from point
    bool radians;      ///< is vAngle in radians (true) or degrees (false)?

    void setAngle(double a, bool r);
    void checkAngle(double a, bool r);
    double getAngle();
    double convertDegrees2Radians();
    bool getRadians();

public:

    Polar();
    Polar(double x, double y, double a, bool r);
    Polar(tuple<double, double, double> xya, bool r);

    void getVector(double *x, double *y, double *a);
    tuple<double, double, double> getVector();

    void setVector(double x, double y, double a);
    void setVector(tuple<double, double, double> xya);

    bool isDegrees();
    bool isRadians();

    double cosAngle();
    double sinAngle();

    void print() override;
    void print(double x, double y, double a);

};

#endif //COORD_POLAR_H
