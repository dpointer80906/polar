#include <iostream>
#include "Point.h"
#include "Polar.h"
#include "Vertices.h"

using namespace std;

void testPoint();
void testPolar();
void testVertices();

int main() {
    testPoint();
    testPolar();
    testVertices();
    return 0;
}

/*!
 *
 */
void testPoint() {
    cout << endl << "===== testPoint" << endl;

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
    coord.print(x, y);
}

/*!
 *
 */
void testPolar() {
    cout << endl << "===== testPolar" << endl;
    Polar *coord0 = new Polar();
    coord0->print();
    double x = 5.3;
    double y = 3.5;
    double angle = 34.0;
    Polar coord1(x, y, angle);
    coord1.print();
    Polar coord2(make_tuple(x, y, angle));
    coord2.print();
    coord2.vector(&x, &y, &angle);
    coord2.print(x, y, angle);
    tuple<double, double, double> xya = coord2.vector();
    coord2.print(get<0>(xya), get<1>(xya), get<2>(xya));
    cout << "degrees: " << boolalpha << coord2.isDegrees() << endl;
    cout << "radians: " << boolalpha << coord2.isRadians() << endl;
    cout << "degrees: " << boolalpha << coord0->isDegrees() << endl;
    cout << "radians: " << boolalpha << coord0->isRadians() << endl;
    coord0 = new Polar(true);
    cout << "degrees: " << boolalpha << coord0->isDegrees() << endl;
    cout << "radians: " << boolalpha << coord0->isRadians() << endl;
}

/*!
 *
 */
void testVertices() {
    cout << endl << "===== testVertices" << endl;
    double x = 3.0;
    double y = 3.0;
    double angle = 270.0;
    double front = 1.2;
    double side = 2.5;
    Vertices vertices(Vertices(x, y, angle, front, side));
    vertices.print();
    x = 5.3;
    y = 3.5;
    angle = 34.0;
    vertices.update(x, y, angle);
    vertices.print();
}
