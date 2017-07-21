/*!
 * Simple quick test for vertices class.
 */
// TODO make a real unit test

#include <iostream>
#include "Vertices.h"

using namespace std;

void testVertices();

int main() {
    testVertices();
    return 0;
}
void testVertices() {
    cout << endl << "===== testVertices" << endl;
    double x = 3.0;
    double y = 3.0;
    double angle = 270.0;
    double front = 1.2;
    double side = 2.5;
    Vertices vertices(Vertices(x, y, angle, false, front, side));
    vertices.print();
    x = 5.3;
    y = 3.5;
    angle = 34.0;
    vertices.update(x, y, angle);
    vertices.print();
}
