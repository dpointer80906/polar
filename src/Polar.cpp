#include "Polar.h"

/*!
 * Default constructor.
 */
Polar::Polar() {
    this->setXY(0.0, 0.0);
    this->setAngle(0.0, false);
}

/*!
 * Separate x,y,angle constructor.
 *
 * @param x     [in] initial x of polar coordinate.
 * @param y     [in] initial y of polar coordinate.
 * @param a     [in] initial angle of polar coordinate.
 * @param r     [in] angle in radians (true) or degrees (false).
 */
Polar::Polar(double x, double y, double a, bool r) {
    this->setXY(x, y);
    this->setAngle(a, r);
}

/*!
 * Tuple x,y,angle constructor.
 *
 * @param xya   [in] a tuple x,y,angle value for initialization.
 * @param r     [in] angle in radians (true) or degrees (false).
 */
Polar::Polar(tuple<double, double, double> xya, bool r) {
    this->setXY(get<0>(xya), get<1>(xya));
    this->setAngle(get<2>(xya), r);
}

/*!
 * Angle setter.
 *
 * This method will set the new angle value and the new radians value if the angle
 * value is in the range range[0.0, 360.0] degrees. When called by a constructor,
 * rhw r param comes from the constructor arg list. When called by a method, the
 * r param is simply the current value of the class var radians. Kind of redundant,
 * sure, but this leads to less code which is hopefully easier to read.
 *
 * Also, there was a dependency that radians had to be set before setAngle() was
 * called. This method is the result of removing this dependency for the constructors.
 *
 * @param a [in] the proposed new angle value.
 * @param r [in] the proposed new radians value.
 */
void Polar::setAngle(double a, bool r) {
    try {
        this->checkAngle(a, r);
    }
    catch (const char* msg) {     // TODO make specific exception
        cerr << msg << endl;
        return;
    }
    this->angle = a;
    this->radians = r;
}

/*!
 * Check that the desired value of the new angle is in range[0.0, 360.0] degrees.
 *
 * @param a [in] the angle value to check.
 * @throws
 */
void Polar::checkAngle(double a, bool radians) {
    const int shift = 100;
    long angle = lround(a * shift);
    int lower =  0;
    int upper = (radians) ? 2*shift : 360*shift;
    if((angle < lower) || (angle > upper)) {
        throw "angle must be in the range[0.0, 360.0] degrees or range[0.0, 2.0] radians."; // TODO make specific exception
    }
}

/*!
 * Angle getter.
 *
 * @return the current angle value.
 */
double Polar::getAngle() {
    return angle;
}

/*!
 * Convert angle in degrees to radians if appropriate.
 *
 * @return the current angle in radians.
 */
double Polar::convertDegrees2Radians() {
    return((isDegrees()) ? getAngle() * M_PI/180.0 : getAngle());
}

/*!
 * Radians getter.
 *
 * @return the current radians value.
 */
bool Polar::getRadians() {
    return radians;
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
 * @param x     [in] new x value of polar coordinate.
 * @param y     [in] new y value of polar coordinate.
 * @param a     [in] new angle value of polar coordinate.
 */
void Polar::setVector(double x, double y, double a) {
    setXY(x, y);
    setAngle(a, getRadians());
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
 * Utility function to return cosine of current polar coordinate angle.
 *
 * @return the cosine of the current angle in radians.
 */
double Polar::cosAngle() {
    return cos(convertDegrees2Radians());
}

/*!
 * Utility function to return sine of current polar coordinate angle.
 *
 * @return the sine of the current angle in radians.
 */
double Polar::sinAngle() {
    return sin(convertDegrees2Radians());
}

/*!
 * Utility function: is angle in degrees?
 *
 * @return true if angle value in degrees.
 */
bool Polar::isDegrees() {
    return !getRadians();
}

/*!
 * Utility function: is angle in radians?
 *
 * @return true if angle value in radians.
 */
bool Polar::isRadians() {
    return getRadians();
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
    string units = (isRadians()) ? "radians" : "degrees";
    cout << "x: " << x << " y: " << y << " angle: " << a << " " << units << endl;
}
