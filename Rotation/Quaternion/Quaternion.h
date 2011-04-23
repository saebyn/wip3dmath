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
    void set(double xrot, double yrot, double zrot);
    void get(double &xrot, double &yrot, double &zrot) const;
    // Quaternion rotation.
    void set(const Quaternion& rotation);
    void get(Quaternion& rotation) const;
    /* some basic things first */
    Quaternion get_x_axis() const;
    Quaternion get_y_axis() const;
    Quaternion get_z_axis() const;
    /* basic math operators */
    Quaternion operator+ (Quaternion &) const;
    Quaternion operator- (Quaternion &) const;
    Quaternion inverse() const;
    /* equality operators */
    bool operator== (Quaternion &) const;
    bool operator!= (Quaternion &) const;
    /* rotation operators */
    const Quaternion& rotate(double &x, double &y, double &z) const;
    const Quaternion& rotate(Point &point) const;
    //Point rotate(const Point &point) const;
    /* Matrix operations */
    Matrix get_matrix() const;
    /* Constructors */
    Quaternion(double, double, double, double);
    Quaternion();
 protected:
    Quaternion operator* (double) const;
    Quaternion operator* (const Quaternion &) const;
    Quaternion operator/ (double) const;
    double length() const;
    Quaternion normal() const;
    Quaternion conjugate() const;
    void set(double, double, double, double);
    double w, x, y, z;
};

}; // namespace wip3dmath

#endif /* !defined(_WIP3DMATH_ROTATION_QUATERNION_QUATERNION_H_) */
