#include "Polar.h"

/*!
 * Default constructor.
 *
 * @param r [in] angle class var in radians (true) or degrees (false).
 */
Polar::Polar(bool r) : radians(r) {
    this->setAngle(0.0);
}

/*!
 * Separate x,y,angle constructor.
 *
 * @param x     [in] initial x of polar coordinate.
 * @param y     [in] initial y of polar coordinate.
 * @param a     [in] initial angle of polar coordinate.
 * @param r     [in] angle in radians (true) or degrees (false).
 */
Polar::Polar(double x, double y, double a, bool r) : radians(r) {
    this->setXY(x, y);
    this->setAngle(a);
}

/*!
 * Tuple x,y,angle constructor.
 *
 * @param xya   [in] a tuple x,y,angle value for initialization.
 * @param r     [in] angle in radians (true) or degrees (false).
 */
Polar::Polar(tuple<double, double, double> xya, bool r) : radians(r) {
    this->setXY(get<0>(xya), get<1>(xya));
    this->setAngle(get<2>(xya));
}

/*!
 * Angle setter.
 *
 * This method will set the new angle value and the new radians value if the angle
 * value is in the range range[0.0, 360.0] degrees.
 *
 * @param a [in] the proposed new angle value.
 */
void Polar::setAngle(double a) {
    long angle = lround(a * shift);
    int upper = (getRadians()) ? (maxRadians * shift) : (maxDegrees * shift);
    if((angle < minAngle) || (angle > upper)) {
        cerr << "ERROR angle " << a << " " << angleUnits() << " rejected as invalid." << endl;
        cerr << "angle " << " must be in the range" << angleRange() << endl;
        return;
    }
    this->angle = a;
}

/*!
 * Distinct x,y,angle getter.
 *
 * @param x [in, out] reference to returned x value of polar coordinate.
 * @param y [in, out] reference to returned y value of polar coordinate.
 * @param a [in, out] reference to returned angle value of polar coordinate.
 */
void Polar::getVector(double *x, double *y, double *a) {
    *x = getX();
    *y = getY();
    *a = getAngle();
}

/*!
 * Tuple x,y,angle getter.
 *
 * @return the current x,y,angle tuple values.
 */
tuple<double, double, double> Polar::getVector() {
    return make_tuple(getX(), getY(), getAngle());
}

/*!
 * Distinct x,y,angle value setter.
 *
 * @param x [in] new x value of polar coordinate.
 * @param y [in] new y value of polar coordinate.
 * @param a [in] new angle value of polar coordinate.
 */
void Polar::setVector(double x, double y, double a) {
    setXY(x, y);
    setAngle(a);
}

/*!
 * Tuple x,y,angle setter.
 *
 * @param xya [in] the new x,y,angle values to set.
 */
void Polar::setVector(tuple<double, double, double> xya) {
    setVector(get<0>(xya), get<1>(xya), get<2>(xya));
}

/*!
 * Utility print function used to check current polar coordinate values.
 */
void Polar::print() {
    print(getX(), getY(), getAngle());
}

/*!
 * Utility print function used to print specified polar coordinate values.
 *
 * @param x [in] x coordinate to print.
 * @param y [in] y coordinate to print.
 * @param a [in] angle value to print.
 */
void Polar::print(double x, double y, double a) {
    cout << "x: " << x << " y: " << y << " angle: " << a << " " << angleUnits() << endl;
}
