// Calculate bounding rectangle vertices given a center point and an angle for a given height and width.
//
// David Pointer <david.b.pointer@gmail.com>
//

#ifndef COORD_VERTICES_H
#define COORD_VERTICES_H
#include <tuple>
#include <map>
#include "Point.h"
#include "Polar.h"

class Vertices {

    Polar polar;          // x,y,angle for center of tank and angle normal to front of tank
    double front;         // front dimension of tank (inches), does not change once instantiated
    double side;          // side dimension of tank (inches), does not change once instantiated
    Point front_left;     // calculated upper front left vertex point of bounding rectangle
    Point front_right;    // calculated upper front right vertex point of bounding rectangle
    Point rear_right;     // calculated lower rear right vertex point of bounding rectangle
    Point rear_left;      // calculated lower rear left vertex point of bounding rectangle

    Point rotate(Point unrotated);
    void calcVertices();

public:

    Vertices();
    Vertices(double x, double y, double angle, double front, double side);

    std::map<std::string, Point> vertices();

    void print();
    void printVertices();

};

#endif //COORD_VERTICES_H
