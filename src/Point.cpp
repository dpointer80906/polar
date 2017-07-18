#include "Point.h"

/*!
 * Default constructor.
 */
Point::Point() {
    xy(make_tuple(0.0, 0.0));
}

/*!
 * Separate x,y values constructor.
 *
 * @param x [in] the initial x axis value for this point.
 * @param y [in] the initial y axis value for this point.
 */
Point::Point(double x, double y) {
    xy(make_tuple(x, y));
}

/*!
 * Tuple x,y constructor.
 */
Point::Point(tuple<double, double> xy) {
    Point::xy(xy);
}

/*!
 * Tuple x,y getter.
 *
 * @return the point x,y coordinate tuple.
 */
tuple<double, double> Point::xy() {
    return getXY();
}

/*!
 * Separate x,y values getter.
 *
 * @param x  [in,out] the var reference for the x coordinate.
 * @param y  [in,out] the var reference for the y coordinate.
 */
void Point::xy(double *x, double *y) {
    *x = Point::x();
    *y = Point::y();
}

/*!
 * x coordinate getter.
 *
 * @return the x coordinate for this point instance.
 */
double Point::x() {
    return get<0>(xy());
}

/*!
 * y coordinate getter.
 *
 * @return the y coordinate for this point instance.
 */
double Point::y() {
    return get<1>(xy());
}

/*!
 * Tuple x,y setter.
 *
 * @param xy [in] tuple x,y value to set.
 */
void Point::xy(tuple<double, double> xy) {
    Point::setXY(xy);
}

/*!
 * Separate x,y value setter.
 *
 * @param x [in] new x coordinate to set.
 * @param y [in] new y coordinate to set.
 */
void Point::xy(double x, double y) {
    Point::x(x);
    Point::y(y);
}

/*!
 * x coordinate setter.
 *
 * @param x [in] the new x coordinate for this point.
*/
void Point::x(double x) {
    tuple<double, double> xy = Point::xy();
    get<0>(xy) = x;
    Point::xy(xy);
}

/*!
 * y coordinate setter.
 * 
 * @param y [in] the new y coordinate for this point.
*/
 void Point::y(double y) {
    tuple<double, double> xy = Point::xy();
    get<1>(xy) = y;
    Point::xy(xy);
}

/*!
 * Utility print function used to check current point coordinate values.
 */
void Point::print() {
    cout << "x: " << x() << " y: " << y() << endl;
}

/*!
 * Utility print function used to print coordinate values in the same manner as print().
 *
 * @param x [in] x coordinate value to print.
 * @param y [in] y coordinate value to print.
 */
void Point::print(double x, double y) {
    cout << "x: " << x << " y: " << y << endl;
}