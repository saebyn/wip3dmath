/*! \file Euler.cc
 * \brief Euler class.
 */

/* Copyright (c) 2006 John David Weaver
 * All Rights Reserved.
 */

#include "wip3dmath.h" 

namespace wip3dmath {

// Euler angles in degrees.
void 
Euler::set(double xrot, double yrot, double zrot) {
    this->xrot = xrot * PIOVER180;
    this->yrot = yrot * PIOVER180;
    this->zrot = zrot * PIOVER180;
}

void 
Euler::get(double &xrot, double &yrot, double &zrot) const {
    xrot = this->xrot/PIOVER180;
    yrot = this->yrot/PIOVER180;
    zrot = this->zrot/PIOVER180;
}

// Quaternion rotation.
void 
Euler::get(Quaternion& rotation) const {
    rotation.set(xrot, yrot, zrot);
}

Euler 
Euler::get_x_axis() const {
    Euler a(xrot, 0, 0);

    return a;
}

Euler 
Euler::get_y_axis() const {
    Euler a(0, yrot, 0);

    return a;
}

Euler 
Euler::get_z_axis() const {
    Euler a(0, 0, zrot);

    return a;
}

/* basic math operators */
Euler 
Euler::operator+ (Euler &other) const {
    Euler a;

    a.xrot = xrot + other.xrot;
    a.yrot = yrot + other.yrot;
    a.zrot = zrot + other.zrot;

    return a;
}

Euler&
Euler::operator+= (const Euler &other) {
    xrot += other.xrot;
    yrot += other.yrot;
    zrot += other.zrot;

    return *this;
}

Euler 
Euler::operator- (Euler &other) const {
    Euler a;

    a.xrot = xrot - other.xrot;
    a.yrot = yrot - other.yrot;
    a.zrot = zrot - other.zrot;

    return a;
}

/* equality operators */
bool 
Euler::operator== (const Euler &other) const {
    return ( xrot==other.xrot and yrot==other.yrot and zrot==other.zrot );
}

bool 
Euler::operator!= (const Euler &other) const {
    return ( xrot!=other.xrot or yrot!=other.yrot or zrot!=other.zrot );
}

/* Euler operators */
const Euler& 
Euler::rotate(double &x, double &y, double &z) const {
    Point p(x, y, z);

    rotate(p);

    p.get(x, y, z);

    return *this;
}

const Euler& 
Euler::rotate(Point &point) const {
    point = get_matrix() * point;

    return *this;
}

Matrix 
Euler::get_matrix() const {
    Matrix result;
    double *matrix = new double[16];
    double x, y, z;
    double a;

    x = y = z = 0;
    a = sqrt( pow(xrot,2) + pow(yrot,2) + pow(zrot,2) );
    if ( a != 0 ) {
        x = xrot / a;
        y = yrot / a;
        z = zrot / a;
    }
    double x2 = pow(x,2);
    double y2 = pow(y,2);
    double z2 = pow(z,2);
    double xy = x*y;
    double xz = x*z;
    double yz = y*z;
    double c = cos(a);
    double s = sin(a);
    double mc = 1.0-c;

    matrix[0] = x2*mc+c;   matrix[4] = xy*mc-z*s; matrix[8]  = xz*mc+y*s; matrix[12] = 0.0;
    matrix[1] = xy*mc+z*s; matrix[5] = y2*mc+c;   matrix[9]  = yz*mc-x*s; matrix[13] = 0.0;
    matrix[2] = xz*mc-y*s; matrix[6] = yz*mc+x*s; matrix[10] = z2*mc+c;   matrix[14] = 0.0;
    matrix[3] = 0.0;       matrix[7] = 0.0;       matrix[11] = 0.0;       matrix[15] = 1.0;

    result.set(matrix);
    delete [] matrix;
    return result;
}

Euler::Euler(double pitch, double yaw, double roll) {
    set(xrot, yrot, zrot);
}

} // namespace wip3dmath
