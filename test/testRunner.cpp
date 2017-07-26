//
// Created by David Pointer on 7/25/17.
//
#include "catchWrapper.h"
#include "../src/Point.h"
#include "../src/Polar.h"
#include "../src/Vertices.h"

TEST_CASE("Point.", "[Point]") {
    double x = 0.0;
    double y = 0.0;
    double x0 = 1.1;
    double y0 = 2.1;
    double x1 = 6.12;
    double y1 = 1.15;
    Point coord;
    Point coord0(x0, y0);
    Point coord1(make_tuple(x1, y1));

    SECTION("Constructor initial values and separate x and y getters.") {
        REQUIRE(coord.getX() == x);
        REQUIRE(coord.getY() == y);
        REQUIRE(coord0.getX() == x0);
        REQUIRE(coord0.getY() == y0);
        REQUIRE(coord1.getX() == x1);
        REQUIRE(coord1.getY() == y1);
        coord.print();
        coord0.print();
        coord1.print();
    }

    SECTION("Single value x setters.") {
        x = 2.78;
        x0 = x + 1.0;
        x1 = x + 2.0;
        coord.setX(x);
        coord0.setX(x0);
        coord1.setX(x1);
        REQUIRE(coord.getX() == x);
        REQUIRE(coord.getY() == y);
        REQUIRE(coord0.getX() == x0);
        REQUIRE(coord0.getY() == y0);
        REQUIRE(coord1.getX() == x1);
        REQUIRE(coord1.getY() == y1);
    }

    SECTION("Single value y setters.") {
        y = 4.5;
        y0 = y + 1.1;
        y1 = y + 2.1;
        coord.setY(y);
        coord0.setY(y0);
        coord1.setY(y1);
        REQUIRE(coord.getX() == x);
        REQUIRE(coord.getY() == y);
        REQUIRE(coord0.getX() == x0);
        REQUIRE(coord0.getY() == y0);
        REQUIRE(coord1.getX() == x1);
        REQUIRE(coord1.getY() == y1);
    }

    SECTION("Tuple x,y setters.") {
        x = 21.34;
        y = 4.545;
        x0 = x + 1.34;
        y0 = y + 1.45;
        x1 = x + 2.34;
        y1 = y + 2.56;
        coord.setXY(make_tuple(x, y));
        coord0.setXY(make_tuple(x0, y0));
        coord1.setXY(make_tuple(x1, y1));
        REQUIRE(coord.getX() == x);
        REQUIRE(coord.getY() == y);
        REQUIRE(coord0.getX() == x0);
        REQUIRE(coord0.getY() == y0);
        REQUIRE(coord1.getX() == x1);
        REQUIRE(coord1.getY() == y1);
    }

    SECTION("Separate x,y getters.") {
        double a, b;
        coord1.getXY(&a, &b);
        REQUIRE(a == x1);
        REQUIRE(b == y1);
    }

    SECTION("Tuple x,y getters.") {
        tuple<double, double> xy = coord0.getXY();
        REQUIRE(get<0>(xy) == x0);
        REQUIRE(get<1>(xy) == y0);
    }

}

TEST_CASE("Polar.", "[Polar]") {
    double x = 0.0;
    double y = 0.0;
    double angle = 0.0;
    double x0 = 1.1;
    double y0 = 2.1;
    double angle0 = 45.0;
    double x1 = 6.12;
    double y1 = 1.15;
    double angle1 = 1.3;
    bool radians = false;
    double a, b, c;
    double a0, b0, c0;
    double a1, b1, c1;
    tuple<double, double, double> xya;
    tuple<double, double, double> xya0;
    tuple<double, double, double> xya1;
    Polar coord(radians);
    Polar coord0(x0, y0, angle0, radians);
    radians = true;
    Polar coord1(make_tuple(x1, y1, angle1), radians);

    SECTION("Constructor initial values and separate x,y,a getVector().") {
        coord.getVector(&a, &b, &c);
        coord0.getVector(&a0, &b0, &c0);
        coord1.getVector(&a1, &b1, &c1);
        REQUIRE(a == x);
        REQUIRE(b == y);
        REQUIRE(c == angle);
        REQUIRE(coord.isDegrees());
        REQUIRE(a0 == x0);
        REQUIRE(b0 == y0);
        REQUIRE(c0 == angle0);
        REQUIRE(coord0.isDegrees());
        REQUIRE(a1 == x1);
        REQUIRE(b1 == y1);
        REQUIRE(c1 == angle1);
        REQUIRE(coord1.isRadians());
    }

    SECTION("Constructor initial values and tuple x,y,a getVector().") {
        xya = coord.getVector();
        xya0 = coord0.getVector();
        xya1 = coord1.getVector();
        REQUIRE(get<0>(xya) == x);
        REQUIRE(get<1>(xya) == y);
        REQUIRE(get<2>(xya) == angle);
        REQUIRE(coord.isDegrees());
        REQUIRE(get<0>(xya0) == x0);
        REQUIRE(get<1>(xya0) == y0);
        REQUIRE(get<2>(xya0) == angle0);
        REQUIRE(coord0.isDegrees());
        REQUIRE(get<0>(xya1) == x1);
        REQUIRE(get<1>(xya1) == y1);
        REQUIRE(get<2>(xya1) == angle1);
        REQUIRE(coord1.isRadians());
    }

    SECTION("Separate x,y,a setVector().") {
        a = 5.3;
        b = 3.5;
        c = 34.0;
        a0 = 55.35;
        b0 = 34.3;
        c0 = 270.1;
        a1 = 12.5;
        b1 = 13.3;
        c1 = 0.9;
        coord.setVector(a, b, c);
        coord0.setVector(a0, b0, c0);
        coord1.setVector(a1, b1, c1);
        xya = coord.getVector();
        xya0 = coord0.getVector();
        xya1 = coord1.getVector();
        REQUIRE(get<0>(xya) == a);
        REQUIRE(get<1>(xya) == b);
        REQUIRE(get<2>(xya) == c);
        REQUIRE(coord.isDegrees());
        REQUIRE(get<0>(xya0) == a0);
        REQUIRE(get<1>(xya0) == b0);
        REQUIRE(get<2>(xya0) == c0);
        REQUIRE(coord0.isDegrees());
        REQUIRE(get<0>(xya1) == a1);
        REQUIRE(get<1>(xya1) == b1);
        REQUIRE(get<2>(xya1) == c1);
        REQUIRE(coord1.isRadians());
    }

    SECTION("Tuple x,y,a setVector().") {
        a = 5.3;
        b = 3.5;
        c = 34.0;
        a0 = 55.35;
        b0 = 34.3;
        c0 = 270.1;
        a1 = 12.5;
        b1 = 13.3;
        c1 = 0.9;
        coord.setVector(make_tuple(a, b, c));
        coord0.setVector(make_tuple(a0, b0, c0));
        coord1.setVector(make_tuple(a1, b1, c1));
        xya = coord.getVector();
        xya0 = coord0.getVector();
        xya1 = coord1.getVector();
        REQUIRE(get<0>(xya) == a);
        REQUIRE(get<1>(xya) == b);
        REQUIRE(get<2>(xya) == c);
        REQUIRE(coord.isDegrees());
        REQUIRE(get<0>(xya0) == a0);
        REQUIRE(get<1>(xya0) == b0);
        REQUIRE(get<2>(xya0) == c0);
        REQUIRE(coord0.isDegrees());
        REQUIRE(get<0>(xya1) == a1);
        REQUIRE(get<1>(xya1) == b1);
        REQUIRE(get<2>(xya1) == c1);
        REQUIRE(coord1.isRadians());
    }

    SECTION("Angle sin and cos.") {
        angle = 45.0;
        angle0 = 271.3;
        angle1= 1.235;
        coord.setVector(0.0, 0.0, angle);
        coord0.setVector(0.0, 0.0, angle0);
        coord1.setVector(0.0, 0.0, angle1);
        angle *= M_PI/180.0;
        angle0 *= M_PI/180.0;
        REQUIRE(cos(angle) == coord.cosAngle());
        REQUIRE(cos(angle0) == coord0.cosAngle());
        REQUIRE(cos(angle1) == coord1.cosAngle());
        REQUIRE(sin(angle) == coord.sinAngle());
        REQUIRE(sin(angle0) == coord0.sinAngle());
        REQUIRE(sin(angle1) == coord1.sinAngle());
    }

    SECTION("Invalid setAngle()") {
        xya = coord.getVector();
        xya1 = coord1.getVector();
        coord.setVector(0.0, 0.0, 360.5);
        coord1.setVector(0.0, 0.0, 36.0);
        coord.getVector(&a, &b, &c);
        coord1.getVector(&a1, &b1, &c1);
        REQUIRE(c == get<2>(xya));
        REQUIRE(c1 == get<2>(xya1));
    }
}

TEST_CASE("Vertices.", "[Vertices]") {
    double x = 0.0;
    double y = 0.0;
    Vertices coord(x, y, 0.0, false, 1.5, 2.5);
}
