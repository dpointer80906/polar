#ifndef COORD_VERTICES_H
#define COORD_VERTICES_H
#include <iostream>
#include <tuple>
#include <map>
#include "Point.h"
#include "Polar.h"

using namespace std;

/*!
 * @class Vertices
 *
 * Class to calculate the four rectangle coordinate vertices given a polar coordinate.
 */
class Vertices {

    Polar polar;            ///< x,y,angle polar coordinate, angle is normal to "front"
    const double front;     ///< "front" width dimension
    const double side;      ///< "side" width dimension
    Point frontLeft;        ///< calculated upper front left vertex point of bounding rectangle
    Point frontRight;       ///< calculated upper front right vertex point of bounding rectangle
    Point rearRight;        ///< calculated lower rear right vertex point of bounding rectangle
    Point rearLeft;         ///< calculated lower rear left vertex point of bounding rectangle

    Point rotatePoint(Point unrotated);
    void calcVertices();

public:

    Vertices(double x, double y, double angle, const double front, const double side);

    std::map<std::string, Point> vertices();

    void update(double x, double y, double angle);

    void print();

};

#endif //COORD_VERTICES_H
