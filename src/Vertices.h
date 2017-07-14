//
// Created by David Pointer on 7/13/17.
//

#ifndef COORD_VERTICES_H
#define COORD_VERTICES_H
#include <tuple>
#include "Point.h"
#include "Polar.h"

class Vertices {

    Polar polar;
    float front;
    float side;
    Point front_left;
    Point front_right;
    Point rear_right;
    Point rear_left;

    Point rotate(Point unrotated);

public:

    Vertices();
    Vertices(float x, float y, float angle, float front, float side);

    void print();

};


#endif //COORD_VERTICES_H
