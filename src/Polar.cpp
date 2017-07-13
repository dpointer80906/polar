#include "Polar.h"

// default constructor
Polar::Polar(bool radians /* def false */ ) {
    Polar::angle(0.0);
    Polar::radians = radians;
}

// distinct x,y,angle constructor
Polar::Polar(float x, float y, float angle, bool radians /* def false */ ) {
    Polar::vector(x, y, angle);
    Polar::radians = radians;
}

// tuple constructor
Polar::Polar(std::tuple<float, float, float> xya, bool radians /* def false */ ) {
    Polar::vector(xya);
    Polar::radians = radians;
}

// distinct x,y,angle getter
void Polar::vector(float *x, float *y, float *angle) {
    *x = Polar::point.x();
    *y = Polar::point.y();
    *angle = Polar::angle();
}

// tuple s,y,angle getter
std::tuple<float, float, float> Polar::vector() {
    std::tuple<float, float, float> xya = std::make_tuple(Polar::point.x(), Polar::point.y(), Polar::angle());
    return xya;
}

// x,y,angle setter
void Polar::vector(float x, float y, float angle) {
    Polar::point.xy(x, y);
    Polar::angle(angle);
}

// tuple s,y,angle setter
void Polar::vector(std::tuple<float, float, float> xya) {
    float x = std::get<0>(xya);
    float y = std::get<1>(xya);
    float angle = std::get<2>(xya);
    Polar::point.xy(x, y);
    Polar::angle(angle);
}

