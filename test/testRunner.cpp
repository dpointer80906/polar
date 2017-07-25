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
    Polar coord(false);
    REQUIRE(coord.getX() == x);
    REQUIRE(coord.getY() == y);
}

TEST_CASE("Vertices.", "[Vertices]") {
    double x = 0.0;
    double y = 0.0;
    Vertices coord(x, y, 0.0, false, 1.5, 2.5);
}
