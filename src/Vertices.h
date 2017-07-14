//
// Created by David Pointer on 7/13/17.
//

#ifndef COORD_VERTICES_H
#define COORD_VERTICES_H
#include <tuple>
#include <map>
#include "Point.h"
#include "Polar.h"

class Vertices {

    Polar polar;
    double front;
    double side;
    Point front_left;
    Point front_right;
    Point rear_right;
    Point rear_left;

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
