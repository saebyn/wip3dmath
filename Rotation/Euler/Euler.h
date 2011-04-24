/*! \file Euler.h
 * \brief Header file for abstract class Euler.
 */

/* Copyright (c) 2006 John David Weaver
 * All Rights Reserved.
 */

#if !defined(_WIP3DMATH_ROTATION_EULER_EULER_H_)
#define _WIP3DMATH_ROTATION_EULER_EULER_H_

namespace wip3dmath {

//! Euler class.
/*! Provides a abstract datatype representing a euler angle rotation.
 */
class Euler : public Rotation {
 public:
    // Euler angles in degrees.
    void set(double xrot, double yrot, double zrot);
    void get(double &xrot, double &yrot, double &zrot) const;
    // Quaternion rotation.
    void get(Quaternion& rotation) const;
    /**/
    Euler get_x_axis() const;
    Euler get_y_axis() const;
    Euler get_z_axis() const;
    /* basic math operators */
    Euler& operator+= (const Euler &);
    Euler operator+ (Euler &) const;
    Euler operator- (Euler &) const;
    /* equality operators */
    bool operator== (const Euler &) const;
    bool operator!= (const Euler &) const;
    /* rotation operators */
    const Euler& rotate(double &x, double &y, double &z) const;
    const Euler& rotate(Point &point) const;
    Matrix get_matrix() const;
    /* */
    Euler(double xrot, double yrot, double zrot);
    Euler() : xrot(0.0), yrot(0.0), zrot(0.0) {}
 protected:
    double xrot, yrot, zrot;
};

} // namespace wip3dmath

#endif /* !defined(_WIP3DMATH_ROTATION_EULER_EULER_H_) */
