/*! \file Vector.h
 * \brief Header file for Vector.cc.
 */

/* Copyright (c) 2006 John David Weaver
 * All Rights Reserved.
 */

#if !defined(_WIP3DMATH_UNITVECTOR_VECTOR_VECTOR_H_)
#define _WIP3DMATH_UNITVECTOR_VECTOR_VECTOR_H_

namespace wip3dmath {

//! Vector class.
/*! Provides a datatype representing a position and movement in 3-space.
 */

class Point;
class UnitVector;

class Vector : public UnitVector {
 public:
    Vector() : UnitVector() {}
    Vector(const Point &);
    Vector(double, double, double);
    Vector(double, const UnitVector &vec);
    Vector(const Vector &);
    Vector(const UnitVector &vec);
    Point get(void) const;
    void set(const Point &);
    double length(void);
    Vector& operator+= (double w);
    Vector& operator-= (double w);
    Vector operator+ (double w);
    Vector operator- (double w);
    // 
    Vector& operator+= (const Vector &vec);
    Vector& operator-= (const Vector &vec);
    Vector operator+ (const Vector &vec);
    Vector operator- (const Vector &vec);

    Vector& operator*= (const double w);
    Vector operator* (const double w);

    /* I/O methods */
    friend std::ostream& operator<< (std::ostream&, Vector);
};

} // namespace wip3dmath

#endif /* !defined(_WIP3DMATH_POINT_POINT3D_VECTOR_VECTOR_H_) */
