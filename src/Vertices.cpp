#include <iostream>
#include "Polar.h"
#include "Vertices.h"
#include <list>

// default constructor
Vertices::Vertices() {
    Vertices::front = 0.0;
    Vertices::side = 0.0;
    Vertices::calcVertices();
}

// detailed constructor
Vertices::Vertices(double x, double y, double angle, double front, double side) {
    Vertices::polar.vector(x, y, angle);
    Vertices::front = front;
    Vertices::side = side;
    Vertices::calcVertices();
}

// rotate a unrotated point by angle
Point Vertices::rotate(Point unrotated) {
    double normX = unrotated.x() - polar.x();
    double normY = unrotated.y() - polar.y();
    double primeX = (normX * polar.cosAngle() - normY * polar.sinAngle()) + polar.x();
    double primeY = (normY * polar.cosAngle() + normX * polar.sinAngle()) + polar.y();
    return Point(primeX, primeY);
}

// given a center point and an angle, calculate a bounding rectangle vertices
void Vertices::calcVertices() {
    Point unrotated_front_left(polar.x() - Vertices::front/2.0, polar.y() + Vertices::side/2.0);
    Point unrotated_front_right(polar.x() + Vertices::front/2.0, polar.y() + Vertices::side/2.0);
    Point unrotated_rear_right(polar.x() + Vertices::front/2.0, polar.y() - Vertices::side/2.0);
    Point unrotated_rear_left(polar.x() - Vertices::front/2.0, polar.y() - Vertices::side/2.0);
    Vertices::front_left = Vertices::rotate(unrotated_front_left);
    Vertices::front_right = Vertices::rotate(unrotated_front_right);
    Vertices::rear_right = Vertices::rotate(unrotated_rear_right);
    Vertices::rear_left = Vertices::rotate(unrotated_rear_left);
}

// return the four current calculated bounding rectangle
std::map<std::string, Point> Vertices::vertices() {
    return std::map<std::string, Point>{
            {"front_left", Vertices::front_left},
            {"front_right", Vertices::front_right},
            {"rear_right", Vertices::rear_right},
            {"rear_left", Vertices::rear_left}
    };
}

void Vertices::update(double x, double y, double angle) {
    Vertices::polar.x(x);
    Vertices::polar.y(y);
    Vertices::polar.angle(angle);
    Vertices::calcVertices();
}

// simple print function to check init values
void Vertices::print() {
    std::cout << std::endl;
    std::cout << "x: " << Vertices::polar.x() << " y: " << Vertices::polar.y() << " angle: " <<
              Vertices::polar.angle() << " front: " << Vertices::front << " side: " << Vertices::side << std::endl;
    //std::map<std::string, Point> vertices = Vertices::vertices();
    for (auto &elt : Vertices::vertices()) {
        std::cout << "  " << elt.first << ": " << elt.second.x() << " " << elt.second.y() << std::endl;
    }
}
