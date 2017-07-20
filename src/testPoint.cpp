#include <iostream>
#include "Point.h"

using namespace std;

void testPoint();

int main() {
    testPoint();
    return 0;
}

/*!
 *
 */
void testPoint() {
    cout << endl << "===== testPoint" << endl;
    // constructors
    double x = 1.1;
    double y = 2.1;
    Point coord;
    Point coord0(x, y);
    Point coord1(make_tuple(x, y));
    cout << "coord "; coord.print();
    cout << "coord0 "; coord0.print();
    cout << "coord1 "; coord1.print();

    // setters
    x = 2.78;
    y = 4.5;
    coord.setX(x);
    coord.setY(y);
    coord0.setX(x+1.0);
    coord0.setY(y+1.0);
    coord1.setX(x+2.0);
    coord1.setY(y+2.0);
    cout << "coord "; coord.print();
    cout << "coord0 "; coord0.print();
    cout << "coord1 "; coord1.print();
    x = 42.4;
    y = 1.0;
    coord.setXY(x, y);
    coord0.setXY(x+1.0, y+1.0);
    coord1.setXY(x+2.0, y+2.0);
    cout << "coord "; coord.print();
    cout << "coord0 "; coord0.print();
    cout << "coord1 "; coord1.print();
    x = 2.4;
    y = 7.3;
    coord.setXY(make_tuple(x, y));
    coord0.setXY(make_tuple(x+1.0, y+1.0));
    coord1.setXY(make_tuple(x+2.0, y+2.0));
    cout << "coord "; coord.print();
    cout << "coord0 "; coord0.print();
    cout << "coord1 "; coord1.print();

    // getters
    cout << "coord "; coord.print(coord.getX(), coord.getY());
    cout << "coord0 "; coord.print(coord0.getX(), coord0.getY());
    cout << "coord1 "; coord.print(coord1.getX(), coord1.getY());
    cout << "coord "; coord.print(get<0>(coord.getXY()), get<1>(coord.getXY()));
    cout << "coord0 "; coord.print(get<0>(coord0.getXY()), get<1>(coord0.getXY()));
    cout << "coord1 "; coord.print(get<0>(coord1.getXY()), get<1>(coord1.getXY()));
    coord.getXY(&x, &y);
    cout << "coord "; coord.print(x, y);
    coord0.getXY(&x, &y);
    cout << "coord0 "; coord0.print(x, y);
    coord1.getXY(&x, &y);
    cout << "coord1 "; coord1.print(x, y);
}

