/*! \file Point.cc
 * \brief Point class.
 */

/* Copyright (c) 2005, 2006 John David Weaver
 * All Rights Reserved.
 */

#include "wip3dmath.h" 

namespace wip3dmath {

/* some basic things first */
Point& 
Point::operator=(const Point &value) {
    x = value.x;
    y = value.y;
    z = value.z;

    return *this;
}

double *
Point::get(double *array) const
{
    array[0] = x;
    array[1] = y;
    array[2] = z;
    
    return array;
}

void
Point::get(double& xs, double& ys, double& zs) const {
    xs = x;
    ys = y;
    zs = z;
}

double 
Point::get_x() const 
{
    return x;
}

double 
Point::get_y() const 
{
    return y;
}

double 
Point::get_z() const 
{
    return z;
}

void 
Point::set_x(double value) 
{
    x = value;
}

void 
Point::set_y(double value) 
{
    y = value;
}

void 
Point::set_z(double value) 
{
    z = value;
}

void 
Point::set(double xvalue, double yvalue, double zvalue) 
{
    x = xvalue;
    y = yvalue;
    z = zvalue;
}

/* basic math operators */
Point 
Point::operator+ (double value) const 
{
    Point v;
    
    v.set(x+value, y+value, z+value);
    
    return v;
}

Point 
Point::operator+ (const Point &value) const 
{
    Point v;
    
    v.set(x+value.x, y+value.y, z+value.z);
    
    return v;
}

Point 
Point::operator- (double value) const 
{
    Point v;
    
    v.set(x-value, y-value, z-value);
    
    return v;
}

Point 
Point::operator- (Point value) const 
{
    Point v;
    
    v.set(x-value.x, y-value.y, z-value.z);
    
    return v;
}

Point 
Point::operator* (double value) const 
{
    Point v;
    
    v.set(x*value, y*value, z*value);
    
    return v;
}

Point 
Point::operator* (const Point &value) const 
{
    Point v;
    
    v.set(x*value.x, y*value.y, z*value.z);
    
    return v;
}

/*Point
Point::operator* (const Quaternion &value) const
{
    Point result;
    
    result = value * (*this);
    
    return result;
}*/

Point 
Point::operator/ (double value) const 
{
    Point v;
    
    v.set(x/value, y/value, z/value);
    
    return v;
}

Point 
Point::operator/ (const Point &value) const 
{
    Point v;
    
    v.set(x/value.x, y/value.y, z/value.z);
    
    return v;
}

Point& 
Point::operator+= (double value)
{
    *this = *this + value;
    
    return *this;
}

Point& 
Point::operator+= (const Point &value)
{
    *this = *this + value;
    
    return *this;
}

Point& 
Point::operator-= (double value)
{
    *this = *this - value;
    
    return *this;
}

Point& 
Point::operator-= (const Point &value)
{
    *this = *this - value;
    
    return *this;
}

/* equality operators */
bool 
Point::operator== (const Point &value) const 
{
    return x == value.x && y == value.y && z == value.z;
}

bool 
Point::operator!= (const Point &value) const 
{
    return x != value.x || y != value.y || z != value.z;
}

/* Point math methods */
double 
Point::length() const 
{
    return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

double 
Point::distance(const Point &value) const 
{
    return sqrt(pow(x-value.x, 2) + pow(y-value.y, 2) + pow(z-value.z, 2));
}

Point 
Point::normal() const 
{
    Point v;
    
    v = *this / length();
    
    return v;
}

//! trilinear_interpolate method.
/*!
 */
Point
Point::trilinear_interpolate(char axis, 
                              const Point& point1, 
                              const Point& point2, 
                              const Point& point3, 
                              const Point& point4)
{
    Point self;
    switch (axis) {
    case 'x':
        self.x = 1;
        self.y = y;
        self.z = z;
        break;
    case 'z':
        self.x = x;
        self.y = y;
        self.z = 1;
        break;
    case 'y':
    default:
        self.x = x;
        self.y = 1;
        self.z = z;
    }
        
    double minz = fmin(fmin(point1.get_z(), point2.get_z()), fmin(point3.get_z(), point4.get_z()));
    double maxz = fmax(fmax(point1.get_z(), point2.get_z()), fmax(point3.get_z(), point4.get_z()));
    double miny = fmin(fmin(point1.get_y(), point2.get_y()), fmin(point3.get_y(), point4.get_y()));
    double maxy = fmax(fmax(point1.get_y(), point2.get_y()), fmax(point3.get_y(), point4.get_y()));
    double minx = fmin(fmin(point1.get_x(), point2.get_x()), fmin(point3.get_x(), point4.get_x()));
    double maxx = fmax(fmax(point1.get_x(), point2.get_x()), fmax(point3.get_x(), point4.get_x()));
    double zslope = maxz - minz;
    double yslope = maxy - miny;
    double xslope = maxx - minx;
    Point slope(xslope, yslope, zslope);
    Point minimum(minx, miny, minz);
    return self * slope + minimum;
}

bool 
Point::inXZTriangle(Point *triangle[3]) const
{
    double test_area = 0;
    double correct_area = 0;

    for ( int i = 0 ; i < 3 ; i++ ) {
        int point1 = i;
        int point2 = (i + 1) % 3;
        Point B = *(triangle[point1]) - *this;
        Point C = *(triangle[point2]) - *this;
        test_area += 0.5 * fabs(B.get_x()*C.get_z() - C.get_x()*B.get_z());
    }
    
    Point B = *(triangle[1]) - *(triangle[0]);
    Point C = *(triangle[2]) - *(triangle[0]);
    correct_area = 0.5 * fabs(B.get_x()*C.get_z() - C.get_x()*B.get_z());
        
    return test_area == correct_area;
}

/* Rotation methods */

Point&
Point::rotate(const Euler& rotation) {
    rotation.rotate(*this);

    return *this;
}

Point&
Point::rotate(const Euler& rotation, const Point& position) {
    *this += position;

    rotate(rotation);

    *this -= position;

    return *this;
}

Point& 
Point::rotate(const Quaternion& rotation) 
{
    rotation.rotate(*this);

    return *this;
}

Point& 
Point::rotate(const Quaternion& rotation, const Point& position) 
{
    *this -= position;
    
    rotation.rotate(*this);
    
    *this += position;

    return *this;
}

/* Constructors */

Point::Point(const Point &value)
{
    *this = value;
}

Point::Point(double xvalue, double yvalue, double zvalue)
{
    set(xvalue, yvalue, zvalue);
}

Point::Point(void)
{
    set(0, 0, 0);
}

};
