/*! \file UnitVector.h
 * \brief Header file for UnitVector.cc.
 */

/* Copyright (c) 2006 John David Weaver
 * All Rights Reserved.
 */

#if !defined(_WIP3DMATH_UNITVECTOR_UNITVECTOR_H_)
#define _WIP3DMATH_UNITVECTOR_UNITVECTOR_H_

namespace wip3dmath {

//! UnitVector class.
/*! Provides a datatype representing a unit vector in 3D space.
 */

class Rotation;
class Matrix;

class UnitVector {
 public:
    UnitVector(const UnitVector &vec);
    enum Axis {X_AXIS, Y_AXIS, Z_AXIS, NX_AXIS, NY_AXIS, NZ_AXIS};
    UnitVector(Axis axis);

    UnitVector& operator<< (const Rotation &rot);
    UnitVector& operator<< (const Matrix &mat);

    Point get(void) const;

    /* I/O methods */
    friend std::ostream& operator<< (std::ostream&, UnitVector);
 protected:
    UnitVector(double x, double y, double z);
    UnitVector() {}
    void check(void);
    void set(double x, double y, double z);
    double v[4];
};

}; // namespace wip3dmath

#endif /* !defined(_WIP3DMATH_UNITVECTOR_UNITVECTOR_H_) */
