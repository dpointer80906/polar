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

    Polar polar;                    ///< x,y,angle polar coordinate, angle is normal to "front"
    const double front;             ///< "front" width dimension
    const double side;              ///< "side" width dimension
    map<string, Point> vertices;    ///< four rectangular coordinates from vector, front, side

    double getFront();
    double getSide();
    Point rotatePoint(Point unrotated);
    void setVertices();

public:

    Vertices(double x, double y, double angle, bool radians, double front, double side);

    std::map<std::string, Point> getVertices();
    std::map<std::string, Point> update(double x, double y, double angle);

    void print();

};

#endif //COORD_VERTICES_H
