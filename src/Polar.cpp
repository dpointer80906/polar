#include "Polar.h"

/*!
 * Default constructor.
 *
 * @param radians   [in] angle in radians (true) or degrees (false) (default).
 */
Polar::Polar(bool r) {
    vector(0.0, 0.0, 0.0);
    setRadians(r);
}

/*!
 * Distinct x,y,angle value constructor.
 *
 * @param x     [in] initial x of polar coordinate.
 * @param y     [in] initial y of polar coordinate.
 * @param a     [in] initial angle of polar coordinate.
 * @param r     [in] angle in radians (true) or degrees (false) (default).
 */
Polar::Polar(double x, double y, double a, bool r) {
    vector(x, y, a);
    setRadians(r);
}

/*!
 * Tuple x,y,angle constructor.
 *
 * @param xya   [in] a tuple x,y,angle value for initialization.
 * @param r     [in] angle in radians (true) or degrees (false) (default).
 */
Polar::Polar(tuple<double, double, double> xya, bool r) {
    vector(xya);
    setRadians(r);
}

/*!
 * Distinct x,y,angle getter.
 *
 * @param x     [in, out] reference to returned x value of polar coordinate.
 * @param y     [in, out] reference to returned y value of polar coordinate.
 * @param a     [in, out] reference to returned angle value of polar coordinate.
 */
void Polar::vector(double *x, double *y, double *a) {
    *x = Polar::x();
    *y = Polar::y();
    *a = angle();
}

/*!
 * vAngle class variable proxy getter.
 *
 * @return the current value of vAngle.
 */
double Polar::angle() {
    return getAngle();
}

/*!
 * Tuple s,y,angle getter.
 *
 * @return the current x,y,angle tuple values in this instance.
 */
tuple<double, double, double> Polar::vector() {
    return make_tuple(x(), y(), angle());
}

/*!
 * vAngle class variable proxy setter.
 *
 * @param [in] the new value of vAngle.
 */
void Polar::angle(double a) {
    setAngle(a);
}

/*!
 * Distinct x,y,angle value setter.
 *
 * @param x     [in] new x value of polar coordinate.
 * @param y     [in] new y value of polar coordinate.
 * @param a     [in] new angle value of polar coordinate.
 */
void Polar::vector(double x, double y, double a) {
    xy(x, y);
    angle(a);
}

/*!
 * Tuple x,y,angle value setter.
 *
 * @param xya [in] Tuple of new x,y,angle values for this polar coordinate.
 */
void Polar::vector(tuple<double, double, double> xya) {
    vector(get<0>(xya), get<1>(xya), get<2>(xya));
}

/*!
 * Utility function to return cosine of current polar coordinate angle.
 *
 * @return the cosine of the current Angle.
 */
double Polar::cosAngle() {
    double a = (isDegrees()) ? getAngle() * M_PI/180.0 : getAngle();
    return cos(a);
}

/*!
 * Utility function to return sine of current polar coordinate angle.
 *
 * @return the sine of the current Angle.
 */
double Polar::sinAngle() {
    double a = (isDegrees()) ? getAngle() * M_PI/180.0 : getAngle();
    return sin(a);
}

/*!
 * Utility function: is angle in degrees?
 *
 * @return true if angle value in in degrees.
 */
bool Polar::isDegrees() {
    return !getRadians();
}

/*!
 * Utility function: is angle in radians?
 *
 * @return true if angle value in in radians.
 */
bool Polar::isRadians() {
    return getRadians();
}

/*!
 * Utility print function used to check current polar coordinate values.
 */
void Polar::print() {
    cout << "x: " << x() << " y: " << y() << " angle: " << getAngle() << endl;
}

/*!
 * Utility print function used to print specified polar coordinate values.
 *
 * @param x [in] x coordinate to print.
 * @param y [in] y coordinate to print.
 * @param a [in] xangle value to print.
 */
void Polar::print(double x, double y, double a) {
    cout << "x: " << x << " y: " << y << " angle: " << a << endl;
}
