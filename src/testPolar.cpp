/*!
 *
 */
#include "Polar.h"

using namespace std;

void testPolar();

int main() {
    testPolar();
    return 0;
}

void testPolar() {
    cout << endl << "===== testPolar" << endl;
    double x = 5.3;
    double y = 3.5;
    double angle = 34.0;
    Polar coord(x, y, angle, false);
    cout << "coord "; coord.print();

    coord.setVector(x+1.0, y+2.0, angle+3.0);
    Polar coord1(x, y, angle, false);
    Polar coord2;
    coord2.setVector(make_tuple(x+5.0, y+5.0, angle+5.0));
    cout << "coord "; coord.print();
    cout << "coord1 "; coord1.print();
    cout << "coord2 "; coord2.print();

    tuple<double, double, double> xya = coord2.getVector();
    cout << "coord2 "; coord2.print(get<0>(xya), get<1>(xya), get<2>(xya));
    coord2.getVector(&x, &y, &angle);
    cout << "coord2 "; coord2.print(x, y, angle);
    
    angle = 18.0 * M_PI/180.0;
    Polar coord3(x, y, angle, true);
    double deltaC = cos(angle) - coord3.cosAngle();
    double deltaS = sin(angle) - coord3.sinAngle();
    cout << "coord3 "; cout << "angle " << angle << " cos " << cos(angle) << " " << coord3.cosAngle() << endl;
    cout << "coord3 "; cout << "angle " << angle << " sin " << sin(angle) << " " << coord3.sinAngle() << endl;
    cout << "coord3 "; cout << "sin diff " << deltaS << " cos diff " << deltaC << endl;

    Polar coord4(0.0, 0.0, 361.0, false);
}