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

};
