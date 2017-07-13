#include <iostream>
#include "Point.h"

void print(Point coord);
void print(float v);


int main() {
    std::cout << "testPoint" << std::endl;

    float x = 1.1;
    float y = 2.1;
    Point coord(x, y);
    print(coord);

    coord.xy(5.5, 4.7);
    print(coord);
    coord.x(45.6);
    print(coord);
    coord.y(65.4);
    print(coord);

    coord.xy(&x, &y);
    print(x);
    print(y);

    return 0;
}

void print(Point coord) {
    std::cout << coord.x() << std::endl;
    std::cout << coord.y() << std::endl;
}

void print(float v) {
    std::cout << v << std::endl;
}