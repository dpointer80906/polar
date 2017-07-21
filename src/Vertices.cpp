#include "Vertices.h"

/*!
 * Detailed constructor with degrees/radians control..
 *
 * No default constructor, front and side -must- be initialized at construction time.
 * Initialize the vector polar coord, the vertices map, then populate the verticews map.
 *
 * @param x     [in] initial x of polar coordinate.
 * @param y     [in] initial y of polar coordinate.
 * @param a     [in] initial angle of polar coordinate, normal to "front" (radians/degrees depends on "r" flag.
 * @param r     [in] angle in radians (true) or in degrees (false).
 * @param f     [in] constant width "front"
 * @param s     [in] constant length "side"
 */
Vertices::Vertices(double x, double y, double a, bool r, double f, double s) : front(f), side(s), polar(Polar(x, y, a, r)) {
    this->vertices = map<string, Point>{ };
    this->setVertices();
}

/*!
 * Front getter.
 *
 * @return the class var front.
 */
double Vertices::getFront() {
    return front;
}

/*!
 * Side getter.
 *
 * @return the class var side.
 */
double Vertices::getSide() {
    return side;
}

/*!
 * Rotate from a starting point coordinate by angle degrees.
 *
 * First normalize the point to 0,0, execute the rotation by angle,
 * the un-normalize the rotated point.
 *
 * @param unrotated [in] the initial x,y point.
 * @return The initial x,y point moved by "angle" degrees.
 */
Point Vertices::rotatePoint(Point unrotated) {
    double normX = unrotated.getX() - polar.getX();
    double normY = unrotated.getY() - polar.getY();
    double rotX = normX * polar.cosAngle() - normY * polar.sinAngle();
    double rotY = normY * polar.cosAngle() + normX * polar.sinAngle();
    rotX += polar.getX();
    rotY += polar.getY();
    return {rotX, rotY};
}

/*!
 * Given a center point and an angle normal to "front", calculate bounding rectangle vertices.
 *
 * This is called after x,y,angle are changed (Vertices() and update()).
 *
 */
void Vertices::setVertices() {
    double halfFront = getFront()/2.0;
    double halfSide = getSide()/2.0;
    Point unrotated_front_left(polar.getX() - halfFront, polar.getY() + halfSide);
    Point unrotated_front_right(polar.getX() + halfFront, polar.getY() + halfSide);
    Point unrotated_rear_right(polar.getX() + halfFront, polar.getY() - halfSide);
    Point unrotated_rear_left(polar.getX() - halfFront, polar.getY() - halfSide);
    this->vertices["frontLeft"] = Vertices::rotatePoint(unrotated_front_left);
    this->vertices["frontRight"] = Vertices::rotatePoint(unrotated_front_right);
    this->vertices["rearRight"] = Vertices::rotatePoint(unrotated_rear_right);
    this->vertices["rearLeft"] = Vertices::rotatePoint(unrotated_rear_left);
}

/*!
 * Return the four current calculated bounding rectangle vertex x,y coordinate.
 *
 * @return A map of vertex name to calculated vertex x,y point coordinates.
 */
map<string, Point> Vertices::getVertices() {
    return vertices;
}

/*!
 * Update the polar coordinate x,y,angle values and recalculate the bounding rectangle vertex x,y coordinates.
 *
 * @param x         [in] the new x polar coordinate value.
 * @param y         [in] the new x polar coordinate value.
 * @param angle     [in] the new polar angle value.
 * @return the updated bounding rectangle vertex x,y coordinates.
 */
std::map<std::string, Point> Vertices::update(double x, double y, double angle) {
    polar.setVector(x, y, angle);
    setVertices();
    return getVertices();
}

/*!
 * Utility print function used to check init values & vertices.
 */
void Vertices::print() {
    double x, y, a;
    polar.getVector(&x, &y, &a);
    cout << endl << "x: " << x << " y: " << y << " angle: " << a;
    cout << " front: " << getFront() << " side: " << getSide() << endl;
    for (auto elt : getVertices()) {
        cout << "  " << elt.first << ": " << elt.second.getX() << " " << elt.second.getY() << endl;
    }
}


