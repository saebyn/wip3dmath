/*! \file IO.cc
 * \brief I/O Functions.
 */

/* Copyright (c) 2006 John David Weaver
 * All Rights Reserved.
 */

#include "wip3dmath.h"

namespace wip3dmath {

/* Point I/O */
std::ostream& 
operator<< (std::ostream& s, Point v)
{
    return s << "Point(" << v.x << ", " << v.y << ", " << v.z << ")";
}

std::ostream& 
operator<< (std::ostream& s, UnitVector v) {
    return s << "UnitVector(" << v.get() << ")";
}

std::ostream& 
operator<< (std::ostream& s, Vector v) {
    return s << "Vector(" << v.v[0] << ", " << v.get() << ")";
}

std::ostream& 
operator<< (std::ostream& s, Quaternion q) {
    return s << "Quaternion(" << q.w << ", " << q.vector() << ")";
}

std::ostream& 
operator<< (std::ostream& s, Euler r) {
    return s << "Euler(pitch = " << r.xrot << ", yaw = " << r.yrot << ", roll = " << r.zrot << ")";
}

std::ostream&
operator<< (std::ostream& s, Matrix m) {
    return s << "Matrix([["
             << m._11 << " " << m._12 << " " << m._13 << " " << m._14 << "]" << std::endl
             << m._21 << " " << m._22 << " " << m._23 << " " << m._24 << "]" << std::endl
             << m._31 << " " << m._32 << " " << m._33 << " " << m._34 << "]" << std::endl
             << m._41 << " " << m._42 << " " << m._43 << " " << m._44 << "]" << std::endl << "])";
}

}
