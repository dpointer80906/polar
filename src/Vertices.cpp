//
// Created by David Pointer on 7/13/17.
//
#include <iostream>
#include "Polar.h"
#include "Vertices.h"

Vertices::Vertices() {
    Vertices::front = 0.0;
    Vertices::side = 0.0;
}

Vertices::Vertices(float x, float y, float angle, float front, float side) {
    Vertices::polar.vector(x, y, angle);
    Vertices::front = front;
    Vertices::side = side;
}

Point Vertices::rotate(Point unrotated) {
    float normX = unrotated.x() - polar.x();
    float normY = unrotated.y() - polar.y();
    float primeX = (normX * polar.cosAngle() - normY * polar.sinAngle()) + polar.x();
    float primeY = (normY * polar.cosAngle() + normX * polar.sinAngle()) + polar.y();
    return Point(primeX, primeY);
}

void Vertices::print() {
    std::cout << this->polar.x() << " " << this->polar.y() << " " << this->polar.angle() << " " <<
              this->front << " " << this->side << std::endl;

}
