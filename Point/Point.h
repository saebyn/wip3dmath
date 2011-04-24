/*! \file Point.h
 * \brief Header file for Point.cc.
 */

/* Copyright (c) 2005, 2006 John David Weaver
 * All Rights Reserved.
 */

#if !defined(_WIP3DMATH_POINT_POINT_H_)
#define _WIP3DMATH_POINT_POINT_H_

#include <ostream>


namespace wip3dmath {
class Quaternion;
class Euler;

//! Point class.
/*! Provides a datatype representing a 3 dimensional point.
 */
class Point {
 public:
    /* some basic things first */
    Point& operator=(const Point &);
    double* get(double*) const;
    void get(double&, double&, double&) const;
    double get_x() const;
    double get_y() const;
    double get_z() const;
    void set_x(double);
    void set_y(double);
    void set_z(double);
    void set(double, double, double);
    /* basic math operators */
    Point operator+ (double) const;
    Point operator+ (const Point &) const;
    Point operator- (double) const;
    Point operator- (Point) const;
    Point operator* (double) const;
    Point operator* (const Point &) const;
    //Point operator* (const Quaternion &) const;
    Point operator/ (double) const;
    Point operator/ (const Point &) const;
    Point& operator+= (double);
    Point& operator+= (const Point &);
    Point& operator-= (double);
    Point& operator-= (const Point &);
    /* equality operators */
    bool operator== (const Point &) const;
    bool operator!= (const Point &) const;
    /* Point math methods */
    double length() const;
    double distance(const Point &) const;
    Point normal() const;
    Point trilinear_interpolate(char axis, const Point&, const Point&, const Point&, const Point&);
    bool inXZTriangle(Point *triangle[3]) const;
    /* Rotation methods */
    Point& rotate(const Euler&); // Rotation around origin.
    Point& rotate(const Euler&, const Point&); // Rotation around point.
    Point& rotate(const Quaternion&); // Rotation around origin.
    Point& rotate(const Quaternion&, const Point&); // Rotation around point.
    /* I/O methods */
    friend std::ostream& operator<< (std::ostream&, Point);
    /* Constructors */
    Point(const Point &);
    Point(double, double, double);
    Point(void);

    virtual ~Point() {}
 protected:
    double x, y, z;
};

} // namespace wip3dmath

#endif /* !defined(_WIP3DMATH_POINT_POINT_H_) */
