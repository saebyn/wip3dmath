/*! \file Cylinder.cc
 * \brief Cylinder class.
 */

/* Copyright (c) 2006 John David Weaver
 * All Rights Reserved.
 */

#include "wip3dmath.h" 

namespace wip3dmath {

double* 
Cylinder::get(double* buf) const {
    buf[0] = x;
    buf[1] = y;
    buf[2] = z;
    buf[3] = radius;
    buf[4] = height;

    return buf;
}

bool 
Cylinder::inVolume(Point &point) {
    if (distance(point) == 0.0)
        return true;
    else
        return false;
}

double 
Cylinder::distance(Point &point) {
    Point xzpoint(x, point.get_y(), z);

    double xzd = xzpoint.distance(point);
    double ydistance;

    if ( point.get_y() >= (y + height/2.0) )
        ydistance = point.get_y() - (y + height/2.0);
    else if ( point.get_y() <= (y - height/2.0) )
        ydistance = (y - height/2.0) - point.get_y();
    else {
        return 0.0;
    }

    if ( ydistance == 0.0 )
        if ( xzd != 0.0 )
            return fabs(xzd - radius);
        else
            return 0.0;
    else if ( xzd == 0.0 )
        return ydistance;

    return sqrt(pow(xzd-radius, 2.0) + pow(ydistance,2.0)); // distance from outside
                                                            // of cylinder to point.
}

Cylinder::Cylinder() {
    x = y = z = 0;
    radius = height = 1;
}

Cylinder::Cylinder(const Cylinder &orig) {
    *this = orig;
}

Cylinder::Cylinder(const Point &point, double radius, double height) {
    x = point.get_x();
    y = point.get_y();
    z = point.get_z();
    this->radius = radius;
    this->height = height;
}

Cylinder::Cylinder(double x, double y, double z, double radius, double height) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->radius = radius;
    this->height = height;
}

}
