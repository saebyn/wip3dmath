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
Quaternion::set(double pitch, double yaw, double roll) {
    // convert degrees to radians.
    pitch *= PIOVER180;
    yaw *= PIOVER180;
    roll *= PIOVER180;

    // from http://www.j3d.org/matrix_faq/matrfaq_latest.html#Q60
    const float fSinPitch(sin(pitch*0.5F));
    const float fCosPitch(cos(pitch*0.5F));
    const float fSinYaw(sin(yaw*0.5F));
    const float fCosYaw(cos(yaw*0.5F));
    const float fSinRoll(sin(roll*0.5F));
    const float fCosRoll(cos(roll*0.5F));
    const float fCosPitchCosYaw(fCosPitch*fCosYaw);
    const float fSinPitchSinYaw(fSinPitch*fSinYaw);
    x = fSinRoll * fCosPitchCosYaw     - fCosRoll * fSinPitchSinYaw;
    y = fCosRoll * fSinPitch * fCosYaw + fSinRoll * fCosPitch * fSinYaw;
    z = fCosRoll * fCosPitch * fSinYaw - fSinRoll * fSinPitch * fCosYaw;
    w = fCosRoll * fCosPitchCosYaw     + fSinRoll * fSinPitchSinYaw;

    normalize();
}

// Quaternion rotation.
void 
Quaternion::set(const Quaternion& rotation) {
    w = rotation.w;
    x = rotation.x;
    y = rotation.y;
    z = rotation.z;
    normalize();
}

void 
Quaternion::get(Quaternion& rotation) const {
    rotation.set(w, x, y, z);
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

    normalize();
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

void
Quaternion::rotate (Point& value) const {
    value = get_matrix() * value;
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

void
Quaternion::normalize() {
    double magnitude = length();

    if ( magnitude != 0 )
      set(w/magnitude, x/magnitude, y/magnitude, z/magnitude);
}

Quaternion 
Quaternion::normal() const 
{
    Quaternion v;
    double magnitude = length();
    
    if ( magnitude != 0 )
        v = *this / magnitude;
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

void
Quaternion::rotate(double &x, double &y, double &z) const {
    Point p(x, y, z);

    rotate(p);

    x = p.get_x();
    y = p.get_y();
    z = p.get_z();
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
Quaternion::Quaternion(double w0, double x0, double y0, double z0)  : w(w0), x(x0), y(y0), z(z0) {
    normalize();
}

Quaternion::Quaternion(double pitch, double yaw, double roll) : w(1), x(0), y(0), z(0)  {
    set(pitch, yaw, roll);
}

Quaternion::Quaternion(void) : w(1), x(0), y(0), z(0) {
}

}
