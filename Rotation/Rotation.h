/*! \file Rotation.h
 * \brief Header file for abstract class Rotation.
 */

/* Copyright (c) 2006 John David Weaver
 * All Rights Reserved.
 */

#if !defined(_WIP3DMATH_ROTATION_ROTATION_H_)
#define _WIP3DMATH_ROTATION_ROTATION_H_

namespace wip3dmath {

//! Rotation class.
/*! Provides a abstract datatype representing a rotation.
 */
class Rotation {
 public:
    /**/
    /* basic math operators */
    //virtual Rotation operator+ (Rotation &value) const = 0;
    //virtual Rotation operator- (Rotation &value) const = 0;
    /* equality operators */
    //virtual bool operator== (Rotation &value) const = 0;
    //virtual bool operator!= (Rotation &value) const = 0;
    /* rotation operators */
    //virtual const Rotation& rotate(double &x, double &y, double &z) const = 0;
    //virtual const Rotation& rotate(Point &point) const = 0;
    virtual Matrix get_matrix() const {Matrix m; return m;}

    virtual Quaternion get() const = 0;

    virtual ~Rotation() {}
};

} // namespace wip3dmath

#endif /* !defined(_WIP3DMATH_ROTATION_ROTATION_H_) */
