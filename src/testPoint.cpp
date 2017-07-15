#include <iostream>
#include "Point.h"
#include "Polar.h"
#include "Vertices.h"

void testPoint();
void testPolar();
void testVertices();

int main() {

    testPoint();
    testPolar();
    testVertices();
    return 0;
}

void testPoint() {
    std::cout << "testPoint" << std::endl;

    double x = 1.1;
    double y = 2.1;
    Point coord(x, y);
    coord.print();

    coord.xy(5.5, 4.7);
    coord.print();
    coord.x(45.6);
    coord.print();
    coord.y(65.4);
    coord.print();

    coord.xy(65.4, 45.6);
    coord.xy(&x, &y);
    std::cout << x << " " << y << std::endl;
}

void testPolar() {
    std::cout << "testPolar" << std::endl;
    Polar *coord0 = new Polar();
    coord0->print();
    double x = 1.1;
    double y = 2.1;
    double angle = 45.0;
    Polar coord1(x, y, angle);
    coord1.print();
    Polar coord2(std::make_tuple(x, y, angle));
    coord2.print();
    coord2.vector(&x, &y, &angle);
    std::cout << x << " " << y << " " << angle << std::endl;
    std::tuple<double, double, double> xya = coord2.vector();
    std::cout << std::get<0>(xya) << " " << std::get<1>(xya) << " " << std::get<2>(xya) << std::endl;
    std::cout << coord2.isDegrees() << std::endl;
    std::cout << coord2.isRadians() << std::endl;
    std::cout << coord0->isDegrees() << std::endl;
    std::cout << coord0->isRadians() << std::endl;
    coord0 = new Polar(true);
    std::cout << coord0->isDegrees() << std::endl;
    std::cout << coord0->isRadians() << std::endl;
}

void testVertices() {
    std::cout << "testVertices" << std::endl;
    Vertices *vertices = new Vertices();
    vertices->print();
    double x = 11.1;
    double y = 42.1;
    double angle = 270.0;
    double front = 2.6;
    double side = 1.2;
    Vertices v1(x, y, angle, front, side);
    v1.print();
    x = 22.3;
    y = 41.4;
    angle = 45.0;
    v1.update(x, y, angle);
    v1.print();
}
