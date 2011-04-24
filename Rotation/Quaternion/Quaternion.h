/*! \file Quaternion.h
 * \brief Header file for Quaternion.cc.
 */

/* Copyright (c) 2005 John David Weaver
 * All Rights Reserved.
 */

#if !defined(_WIP3DMATH_ROTATION_QUATERNION_QUATERNION_H_)
#define _WIP3DMATH_ROTATION_QUATERNION_QUATERNION_H_

namespace wip3dmath {

//! Quaternion class.
/*! Provides a datatype representing a quaternion.
 */
class Quaternion : public Rotation {
 public:
    // Euler angles in degrees.
    void set(double pitch, double yaw, double roll);
    // Quaternion rotation.
    void set(const Quaternion& rotation);
    void get(Quaternion& rotation) const;
    /* basic math operators */
    Quaternion operator+ (Quaternion &) const;
    Quaternion operator- (Quaternion &) const;
    Quaternion inverse() const;
    /* equality operators */
    bool operator== (Quaternion &) const;
    bool operator!= (Quaternion &) const;
    /* rotation operators */
    void rotate(double &x, double &y, double &z) const;
    void rotate(Point &point) const;
    //Point rotate(const Point &point) const;
    /* Matrix operations */
    Matrix get_matrix() const;
    /* Constructors */
    Quaternion(double w0, double x0, double y0, double z0);
    Quaternion(double pitch, double yaw, double roll);
    Quaternion();
 protected:
    Quaternion operator* (double) const;
    Quaternion operator* (const Quaternion &) const;
    Quaternion operator/ (double) const;
    double length() const;
    Quaternion normal() const;
    void normalize();
    Quaternion conjugate() const;
    void set(double, double, double, double);
    double w, x, y, z;
};

} // namespace wip3dmath

#endif /* !defined(_WIP3DMATH_ROTATION_QUATERNION_QUATERNION_H_) */
