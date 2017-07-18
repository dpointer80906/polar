#include "Vertices.h"

/*!
 * Detailed constructor.
 *
 * No default constructor, front and side -must- be initialized at construction time.
 *
 * @param x         [in] initial x of polar coordinate.
 * @param y         [in] initial y of polar coordinate.
 * @param angle     [in] initial angle of polar coordinate, normal to "front".
 * @param f         [in] constant width "front"
 * @param s         [in] constant length "side"
 */
Vertices::Vertices(double x, double y, double angle, double f, double s) : front(f), side(s) {
    polar.vector(x, y, angle);
    calcVertices();
}

/*!
 * Rotate from a starting point coordinate by angle degrees.
 *
 * First normalize the point to 0,0, execute the rotation by angle,
 * the un-normalize the rotated point.
 *
 * @param unrotated     [in] the starting x,y point.
 * @return A single point x,y coordinate moved by "angle" degrees.
 */
Point Vertices::rotatePoint(Point unrotated) {
    double normX = unrotated.x() - polar.x();
    double normY = unrotated.y() - polar.y();
    double rotX = normX * polar.cosAngle() - normY * polar.sinAngle();
    double rotY = normY * polar.cosAngle() + normX * polar.sinAngle();
    rotX += polar.x();
    rotY += polar.y();
    return Point(rotX, rotY);
}

/*!
 * Given a center point and an angle normal to "front", calculate bounding rectangle vertices.
 *
 * This is called after x,y,angle are changed (Vertices() and update()).
 */
void Vertices::calcVertices() {
    double halfFront = front/2.0;
    double halfSide = side/2.0;
    Point unrotated_front_left(polar.x() - halfFront, polar.y() + halfSide);
    Point unrotated_front_right(polar.x() + halfFront, polar.y() + halfSide);
    Point unrotated_rear_right(polar.x() + halfFront, polar.y() - halfSide);
    Point unrotated_rear_left(polar.x() - halfFront, polar.y() - halfSide);
    frontLeft = Vertices::rotatePoint(unrotated_front_left);
    frontRight = Vertices::rotatePoint(unrotated_front_right);
    rearRight = Vertices::rotatePoint(unrotated_rear_right);
    rearLeft = Vertices::rotatePoint(unrotated_rear_left);
}

/*!
 * Return the four current calculated bounding rectangle vertex x,y coordinate.
 *
 * @return A map of vertex name to calculated vertex x,y point coordinates.
 */
map<string, Point> Vertices::vertices() {
    return map<string, Point>{
            {"frontLeft", frontLeft},
            {"frontRight", frontRight},
            {"rearRight", rearRight},
            {"rearLeft", rearLeft}
    };
}

/*!
 * Update the polar coordinate x,y,angle values and recalculate the bounding rectangle vertex x,y coordinates.
 *
 * @param x         [in] the new x polar coordinate value.
 * @param y         [in] the new x polar coordinate value.
 * @param angle     [in] the new polar angle value.
 */
void Vertices::update(double x, double y, double angle) {
    polar.x(x);
    polar.y(y);
    polar.angle(angle);
    calcVertices();
}

/*!
 * Utility print function used to check init values & vertices.
 */
void Vertices::print() {
    cout << endl << "x: " << polar.x() << " y: " << polar.y() << " angle: " << polar.angle() <<
         " front: " << front << " side: " << side << endl;
    for (auto elt : vertices()) {
        cout << "  " << elt.first << ": " << elt.second.x() << " " << elt.second.y() << endl;
    }
}
