/*! \file UnitVector.cc
 * \brief UnitVector class.
 */

/* Copyright (c) 2006 John David Weaver
 * All Rights Reserved.
 */

#include "wip3dmath.h" 

#include <stdexcept>

namespace wip3dmath {

UnitVector& 
UnitVector::operator<< (const Rotation &rot) {\
    return *this << rot.get_matrix();
}

UnitVector& 
UnitVector::operator<< (const Matrix &mat) {
    Point p = mat * get();
    v[1] = p.get_x();
    v[2] = p.get_y();
    v[3] = p.get_z();
    check();
    return *this;
}

Point 
UnitVector::get(void) const {
    return Point(v[1], v[2], v[3]);
}

UnitVector::UnitVector(const UnitVector &vec) {
    for ( int i = 0 ; i < 4 ; i++ )
        v[i] = vec.v[i];
}

UnitVector::UnitVector(Axis axis) {
    switch ( axis ) {
    case X_AXIS:
        v[1] = 1.0;
        v[2] = 0.0;
        v[3] = 0.0;
        break;
    case Y_AXIS:
        v[1] = 0.0;
        v[2] = 1.0;
        v[3] = 0.0;
        break;
    case Z_AXIS:
        v[1] = 0.0;
        v[2] = 0.0;
        v[3] = 1.0;
        break;
    case NX_AXIS:
        v[1] = -1.0;
        v[2] = 0.0;
        v[3] = 0.0;
        break;
    case NY_AXIS:
        v[1] = 0.0;
        v[2] = -1.0;
        v[3] = 0.0;
        break;
    case NZ_AXIS:
        v[1] = 0.0;
        v[2] = 0.0;
        v[3] = -1.0;
    }
}

UnitVector::UnitVector(double x, double y, double z) {
    set(x, y, z);
}

void 
UnitVector::check(void) {
    double len = sqrt(pow(v[1],2) + pow(v[2],2) + pow(v[3],2));
    if ( 1.0+1.0e-300 < len and len < 1.0-1.0e-300 )
        throw std::domain_error("non-unit vector value in UnitVector instance");
}

void 
UnitVector::set(double x, double y, double z) {
    v[1] = x;
    v[2] = y;
    v[3] = z;
    check();
}

};
