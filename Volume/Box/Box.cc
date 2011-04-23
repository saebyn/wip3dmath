/*! \file Box.cc
 * \brief Box class.
 */

/* Copyright (c) 2005 John David Weaver
 * All Rights Reserved.
 */

#include "wip3dmath.h" 

namespace wip3dmath {

double *
Box::get(double *array) const
{
    array[0] = x;
    array[1] = y;
    array[2] = z;
    array[3] = xhalfwidth;
    array[4] = yhalfwidth;
    array[5] = zhalfwidth;
    
    return array;
}

/* some usful methods */
bool 
Box::inVolume(Point &point)
{
    if ( point.get_x() < x - xhalfwidth || point.get_x() > x + xhalfwidth )
        return false;

    if ( point.get_y() < y - yhalfwidth || point.get_y() > y + yhalfwidth )
        return false;

    if ( point.get_z() < z - zhalfwidth || point.get_z() > z + zhalfwidth )
        return false;

    return true;
}

double 
Box::distance(Point &point)
{
    Point self(x, y, z);
    
    return point.distance(self);
}

/* Constructors */

Box::Box(const Box &value)
{
    *this = value;
}

Box::Box(const Point &point, double xhalfwidthvalue, double yhalfwidthvalue, double zhalfwidthvalue)
{
    x = point.get_x();
    y = point.get_y();
    z = point.get_z();
    xhalfwidth = xhalfwidthvalue;
    yhalfwidth = yhalfwidthvalue;
    zhalfwidth = zhalfwidthvalue;
}

Box::Box(double xvalue, double yvalue, double zvalue, double xhalfwidthvalue, double yhalfwidthvalue, double zhalfwidthvalue)
{
    x = xvalue;
    y = yvalue;
    z = zvalue;
    xhalfwidth = xhalfwidthvalue;
    yhalfwidth = yhalfwidthvalue;
    zhalfwidth = zhalfwidthvalue;
}

};
