#include "Point.h"

/*!
 * Default constructor.
 */
Point::Point() {
    this->setCoord(make_tuple(0.0, 0.0));
}

/*!
 * Separate x,y constructor.
 *
 * @param x [in] the initial x axis coordinate value.
 * @param y [in] the initial y axis coordinate value.
 */
Point::Point(double x, double y) {
    this->setCoord(make_tuple(x, y));
}

/*!
 * Tuple x,y constructor.
 */
Point::Point(tuple<double, double> xy) {
    this->setCoord(xy);
}

/*!
 * Tuple x,y getter.
 *
 * @return the x,y coordinate values.
 */
tuple<double, double> Point::getXY() {
    return coord;
}

/*!
 * Separate x,y values getter.
 *
 * @param x  [in,out] an x coordinate variable reference.
 * @param y  [in,out] an coordinate variable reference.
 */
void Point::getXY(double *x, double *y) {
    *x = getX();
    *y = getY();
}

/*!
 * Single x value getter.
 *
 * @return the x coordinate value.
 */
double Point::getX() {
    return get<0>(getXY());
}

/*!
 * Single y value getter.
 *
 * @return the y coordinate value.
 */
double Point::getY() {
    return get<1>(getXY());
}

/*!
 * Private tuple x,y setter with range checking.
 *
 * Note the constructors call this method.
 *
 * @param xy [in] the new x,y coordinate values to set.
 */
void Point::setCoord(tuple<double, double> xy) {  // TODO error checking against expected max getX,getY.
    this->coord = xy;
}

/*!
 * Tuple x,y setter.
 *
 * @param xy [in] the new x,y coordinate values to set.
 */
void Point::setXY(tuple<double, double> xy) {
    setCoord(xy);
}

/*!
 * Separate x,y setter.
 *
 * @param x [in] the new x coordinate value to set.
 * @param y [in] the new y coordinate value to set.
 */
void Point::setXY(double x, double y) {
    setCoord(make_tuple(x, y));
}

/*!
 * Single value x setter.
 *
 * @param x [in] the new x coordinate value to set.
*/
void Point::setX(double x) {
    setCoord(make_tuple(x, getY()));
}

/*!
 * Single value y setter.
 * 
 * @param y [in] the new y coordinate value to set.
*/
 void Point::setY(double y) {
    setCoord(make_tuple(getX(), y));
}

/*!
 * Utility print function used to check current point coordinate values.
 */
void Point::print() {
    double x = getX();
    double y = getY();
    print(x, y);
}

/*!
 * Utility print function used to print coordinate values in the same manner as print().
 *
 * @param x [in] x coordinate value to print.
 * @param y [in] y coordinate value to print.
 */
void Point::print(double x, double y) {
    cout << "point x: " << x << " y: " << y << endl;
}


