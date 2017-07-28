// Point, Polar, Vertices class unit tests. Uses Catch framework: https://github.com/philsquared/Catch
//
#include "catchWrapper.h"
#include "../src/Point.h"
#include "../src/Polar.h"
#include "../src/Vertices.h"

//< Three sets of expected Point, Polar class variables.
struct Expected {
    double x;
    double y;
    double angle;
};

/*!
 * Check the expected Point class values using all three getters.
 *
 * @param c [in] ptr to Point class.
 * @param e [in] ptr to expected value struct.
 */
void checkPoint(Point *c, Expected *e) {
    // single point value getters
    REQUIRE(c->getX() == e->x);
    REQUIRE(c->getY() == e->y);
    // tuple point value getters
    REQUIRE(get<0>(c->getXY()) == e->x);
    REQUIRE(get<1>(c->getXY()) == e->y);
    // separate point value getters
    double a, b;
    c->getXY(&a, &b);
    REQUIRE(a == e->x);
    REQUIRE(b == e->y);
}

TEST_CASE("Point.", "[Point]") {
    Expected expected = {0.0, 0.0};
    Point coord;

    SECTION("Constructor initial values.") {
        checkPoint(&coord, &expected);
        expected = {2.1, 4.7};
        Point coord0(expected.x, expected.y);
        checkPoint(&coord0, &expected);
        expected = {34.6, 42.42};
        Point coord1(make_tuple(expected.x, expected.y));
        checkPoint(&coord1, &expected);
    }

    SECTION("Single value x setter.") {
        expected.x = 42.678;
        coord.setX(expected.x);
        checkPoint(&coord, &expected);
    }

    SECTION("Single value y setter.") {
        expected.y = 4.5;
        coord.setY(expected.y);
        checkPoint(&coord, &expected);
    }

    SECTION("Tuple x,y setter.") {
        expected.x = 21.34;
        expected.y = 4.545;
        coord.setXY(make_tuple(expected.x, expected.y));
        checkPoint(&coord, &expected);
    }

    SECTION("Separate x,y setter.") {
        expected.x = 210.34;
        expected.y = 40.545;
        coord.setXY(expected.x, expected.y);
        checkPoint(&coord, &expected);
    }

}

/*!
 * Check the expected Polar class values using both getters.
 *
 * @param c [in] ptr to Polar class.
 * @param e [in] ptr to expected value struct.
 */
void checkPolar(Polar *c, Expected *e) {
    double x, y, angle;
    c->getVector(&x, &y, &angle);
    REQUIRE(x == e->x);
    REQUIRE(y == e->y);
    REQUIRE(angle == e->angle);
    tuple<double, double, double> xya = c->getVector();
    REQUIRE(get<0>(xya) == x);
    REQUIRE(get<1>(xya) == y);
    REQUIRE(get<2>(xya) == angle);
}

TEST_CASE("Polar.", "[Polar]") {
    Expected expected = {0.0, 0.0, 0.0};
    bool radians = false;
    Polar coord(radians);

    SECTION("Constructor initial values.") {
        checkPolar(&coord, &expected);
        REQUIRE(coord.isDegrees());
        expected = {2.1, 45.6, 350.0};
        radians = false;
        Polar coord0(expected.x, expected.y, expected.angle, radians);
        checkPolar(&coord0, &expected);
        REQUIRE(coord0.isDegrees());
        expected = {22.12, 454.62, 1.3};
        radians = true;
        Polar coord1(expected.x, expected.y, expected.angle, radians);
        checkPolar(&coord1, &expected);
        REQUIRE(coord1.isRadians());
    }

    SECTION("Separate x,y,a setVector().") {
        expected = {5.3, 3.5, 34.0};
        coord.setVector(expected.x, expected.y, expected.angle);
        checkPolar(&coord, &expected);
        REQUIRE(coord.isDegrees());
    }

    SECTION("Tuple x,y,a setVector().") {
        expected = {1.2, 3.4, 270.0};
        coord.setVector(make_tuple(expected.x, expected.y, expected.angle));
        checkPolar(&coord, &expected);
        REQUIRE(coord.isDegrees());
    }

    SECTION("Angle (degrees) sin and cos.") {
        REQUIRE(coord.isDegrees());
        double angle = 45.0;
        coord.setVector(0.0, 0.0, angle);
        angle *= M_PI/180.0;
        REQUIRE(cos(angle) == coord.cosAngle());
        REQUIRE(sin(angle) == coord.sinAngle());
    }

    SECTION("Angle (radians) sin and cos.") {
        radians = true;
        Polar coord1(radians);
        REQUIRE(coord1.isRadians());
        double angle = 0.9;
        coord1.setVector(0.0, 0.0, angle);
        REQUIRE(cos(angle) == coord1.cosAngle());
        REQUIRE(sin(angle) == coord1.sinAngle());
    }

    SECTION("Invalid setAngle() degrees.") {
        expected = {0.1, 0.2, 34.0};
        coord.setVector(expected.x, expected.y, expected.angle);
        REQUIRE(coord.isDegrees());
        double angle = 360.00001;
        coord.setVector(expected.x, expected.y, angle);
        checkPolar(&coord, &expected);
    }
}

TEST_CASE("Vertices.", "[Vertices]") {
    double x = 0.0;
    double y = 0.0;
    Vertices coord(x, y, 0.0, false, 1.5, 2.5);
}
