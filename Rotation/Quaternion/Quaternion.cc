/*! \file Quaternion.cc
 * \brief Quaternion class.
 */

/* Copyright (c) 2005 John David Weaver
 * All Rights Reserved.
 */

#include "wip3dmath.h" 

namespace wip3dmath {

// xrot, yrot, zrot: Euler angles in degrees.
void 
Quaternion::set(double xrot, double yrot, double zrot)
{
    // convert degrees to radians.
    xrot *= PIOVER180;
    yrot *= PIOVER180;
    zrot *= PIOVER180;

    // convert angles to unit length and find magnitude angle (theta).
    double theta = sqrt( pow(xrot,2) + pow(yrot,2) + pow(zrot,2) );
    if ( theta > 0 ) {
        xrot /= theta;
        yrot /= theta;
        zrot /= theta;
    }

    double sin_thetahalf = sin(theta/2.0);
    double cos_thetahalf = cos(theta/2.0);

    set(cos_thetahalf,
        xrot * sin_thetahalf,
        yrot * sin_thetahalf,
        zrot * sin_thetahalf);
}

void 
Quaternion::get(double &xrot, double &yrot, double &zrot) const {
}

// Quaternion rotation.
void 
Quaternion::set(const Quaternion& rotation) {
    w = rotation.w;
    x = rotation.x;
    y = rotation.y;
    z = rotation.z;
}

void 
Quaternion::get(Quaternion& rotation) const {
    rotation.set(w, x, y, z);
}

//XXX
Quaternion 
Quaternion::get_x_axis() const
{
    Quaternion q;
    return q;
}

Quaternion 
Quaternion::get_y_axis() const
{
    Quaternion q;
    return q;
}

Quaternion 
Quaternion::get_z_axis() const
{
    Quaternion q;
    return q;
}

//! set method.
/*! Sets all values for this Quaternion.
 \param wvalue W
 \param xvalue X
 \param yvalue Y
 \param zvalue Z
 \return void
 */
void 
Quaternion::set(double wvalue, double xvalue, double yvalue, double zvalue) 
{
    w = wvalue;
    x = xvalue;
    y = yvalue;
    z = zvalue;
}

/* basic math operators */
Quaternion 
Quaternion::operator+ (Quaternion &value) const 
{
    Quaternion v;
    
    v.set(w+value.w, x+value.x, y+value.y, z+value.z);
    
    return v;
}

Quaternion 
Quaternion::operator- (Quaternion& value) const 
{
    Quaternion v;
    
    v.set(w-value.w, x-value.x, y-value.y, z-value.z);
    
    return v;
}

Quaternion 
Quaternion::operator* (double value) const 
{
    Quaternion v;
    
    v.set(w*value, x*value, y*value, z*value);
    
    return v;
}

/*Point 
Quaternion::rotate(const Point &value) const 
{
    Point point = get_matrix() * value;

    return point;
}*/

const Quaternion& 
Quaternion::rotate (Point& value) const {
    value = get_matrix() * value;

    return *this;
}

Quaternion 
Quaternion::operator/ (double value) const 
{
    Quaternion v;
    v.set(w/value, x/value, y/value, z/value);
    
    return v;
}

/* equality operators */
bool 
Quaternion::operator== (Quaternion &value) const 
{
    return w == value.w && x == value.x && y == value.y && z == value.z;
}

bool 
Quaternion::operator!= (Quaternion &value) const 
{
    return w != value.w || x != value.x || y != value.y || z != value.z;
}

/* Quaternion math methods */
double 
Quaternion::length() const 
{
    return sqrt(pow(w, 2) + pow(x, 2) + pow(y, 2) + pow(z, 2));
}

Quaternion 
Quaternion::normal() const 
{
    Quaternion v;
    double l = length();
    
    if ( l > 0 )
        v = *this / length();
    else
        v = *this;
    
    return v;
}

Quaternion 
Quaternion::inverse() const
{
    return (conjugate() / ( w * w + MathUtils::dotProduct3(x, y, z, x, y, z)));
}

Quaternion 
Quaternion::conjugate() const
{
    Quaternion v;
    double rx, ry, rz;
    
    rx = -x;
    ry = -y;
    rz = -z;
    v.set(w, rx, ry, rz);
    
    return v;
}

const Quaternion& 
Quaternion::rotate(double &x, double &y, double &z) const {
    Point p(x, y, z);

    rotate(p);

    x = p.get_x();
    y = p.get_y();
    z = p.get_z();

    return *this;
}

Matrix
Quaternion::get_matrix() const 
{
    Matrix result;
    double *matrix = new double[16];
    double twox = x+x;
    double twoy = y+y;
    double twoz = z+z;
    double xx = x * twox;
    double xy = x * twoy;
    double xz = x * twoz;
    double yy = y * twoy;
    double yz = y * twoz;
    double zz = z * twoz;
    double wx = w * twox;
    double wy = w * twoy;
    double wz = w * twoz;

    matrix[0] = 1.0-(yy-zz); matrix[4] = xy - wz;     matrix[8]  = xz + wy;     matrix[12] = 0;
    matrix[1] = xy + wz;     matrix[5] = 1.0-(xx-zz); matrix[9]  = yz - wx;     matrix[13] = 0;
    matrix[2] = xz - wy;     matrix[6] = yz + wx;     matrix[10] = 1.0-(xx-yy); matrix[14] = 0;
    matrix[3] = 0;           matrix[7] = 0;           matrix[11] = 0;           matrix[15] = 1;

    result.set(matrix);
    delete [] matrix;
    return result;
}


/* Constructors */
Quaternion::Quaternion(double wvalue, double xvalue, double yvalue, double zvalue)
{
    set(wvalue, xvalue, yvalue, zvalue);
}

Quaternion::Quaternion(void)
{
    set(1, 0, 0, 0);
}

};
