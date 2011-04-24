/*! \file Vector.cc
 * \brief Vector class.
 */

/* Copyright (c) 2006 John David Weaver
 * All Rights Reserved.
 */

#include "wip3dmath.h" 

namespace wip3dmath {

Point 
Vector::get(void) const {
    return Point(v[0]*v[1], v[0]*v[2], v[0]*v[3]);
}

void 
Vector::set(const Point &p) {
    double w;
    w = sqrt(pow(p.get_x(),2) + pow(p.get_y(),2) + pow(p.get_z(),2));
    v[0] = w;
    if ( w == 0 )
        w = 1;
    v[1] = p.get_x()/w;
    v[2] = p.get_y()/w;
    v[3] = p.get_z()/w;
}

double 
Vector::length(void) {
    return v[0];
}

// Vector math mehods.
Vector& 
Vector::operator+= (double w) {
    v[0] += w;
    return *this;
}
Vector& 
Vector::operator-= (double w) {
    v[0] -= w;
    return *this;
}
Vector 
Vector::operator+ (double w) {
    Vector vec(*this);

    vec.v[0] += w;
    return vec;
}
Vector 
Vector::operator- (double w) {
    Vector vec(*this);

    vec.v[0] -= w;
    return vec;
}
// 
Vector& 
Vector::operator+= (const Vector &vec) {
    double x, y, z;

    x = vec.v[1] * vec.v[0];
    y = vec.v[2] * vec.v[0];
    z = vec.v[3] * vec.v[0];

    v[1] = v[1] * v[0] + x;
    v[2] = v[2] * v[0] + y;
    v[3] = v[3] * v[0] + z;

    v[0] = sqrt(pow(v[1],2) + pow(v[2],2) + pow(v[3],2));
    if (v[0] != 0) {
        v[1] /= v[0];
        v[2] /= v[0];
        v[3] /= v[0];
    }
    return *this;
}
Vector& 
Vector::operator-= (const Vector &vec) {
    double x, y, z;

    x = vec.v[1] * vec.v[0];
    y = vec.v[2] * vec.v[0];
    z = vec.v[3] * vec.v[0];

    v[1] = v[1] * v[0] - x;
    v[2] = v[2] * v[0] - y;
    v[3] = v[3] * v[0] - z;

    v[0] = sqrt(pow(v[1],2) + pow(v[2],2) + pow(v[3],2));
    if (v[0] != 0) {
        v[1] /= v[0];
        v[2] /= v[0];
        v[3] /= v[0];
    }
    return *this;
}
Vector 
Vector::operator+ (const Vector &vec) {
    double x, y, z;
    Vector vecres;

    x = vec.v[1] * vec.v[0];
    y = vec.v[2] * vec.v[0];
    z = vec.v[3] * vec.v[0];

    vecres.v[1] = v[1] * v[0] + x;
    vecres.v[2] = v[2] * v[0] + y;
    vecres.v[3] = v[3] * v[0] + z;

    vecres.v[0] = sqrt(pow(vecres.v[1],2) + pow(vecres.v[2],2) + pow(vecres.v[3],2));
    if (vecres.v[0] != 0) {
        vecres.v[1] /= vecres.v[0];
        vecres.v[2] /= vecres.v[0];
        vecres.v[3] /= vecres.v[0];
    }
    return vecres;
}
Vector 
Vector::operator- (const Vector &vec) {
    double x, y, z;
    Vector vecres;

    x = vec.v[1] * vec.v[0];
    y = vec.v[2] * vec.v[0];
    z = vec.v[3] * vec.v[0];

    vecres.v[1] = v[1] * v[0] - x;
    vecres.v[2] = v[2] * v[0] - y;
    vecres.v[3] = v[3] * v[0] - z;

    vecres.v[0] = sqrt(pow(vecres.v[1],2) + pow(vecres.v[2],2) + pow(vecres.v[3],2));
    if (vecres.v[0] != 0) {
        vecres.v[1] /= vecres.v[0];
        vecres.v[2] /= vecres.v[0];
        vecres.v[3] /= vecres.v[0];
    }
    return *this;
}

Vector& 
Vector::operator*= (const double w) {
    v[0] *= w;

    return *this;
}

Vector 
Vector::operator* (const double w) {
    Vector res;

    for ( int i = 1 ; i < 4 ; i++ )
        res.v[i] = v[i];

    res.v[0] = v[0] * w;

    return res;
}

Vector 
Vector::operator* (const Vector& other) const {
  double rx, ry, rz;

  MathUtils::crossProduct3(v[1] * v[0], v[2] * v[0], v[3] * v[0],
                           other.v[1] * other.v[0],
                           other.v[2] * other.v[0],
                           other.v[3] * other.v[0],
                           &rx, &ry, &rz);

  Vector v(rx, ry, rz);

  return v;
}

double 
Vector::dot(const Vector& other) const {
  return MathUtils::dotProduct3(v[1] * v[0], v[2] * v[0], v[3] * v[0],
                                other.v[1] * other.v[0],
                                other.v[2] * other.v[0],
                                other.v[3] * other.v[0]);
}


Vector::Vector(const Point &p) {
    v[0] = sqrt(pow(p.get_x(),2) + pow(p.get_y(),2) + pow(p.get_z(),2));
    if ( v[0] != 0 ) {
        v[1] = p.get_x() / v[0];
        v[2] = p.get_y() / v[0];
        v[3] = p.get_z() / v[0];
    } else {
        v[1] = p.get_x();
        v[2] = p.get_y();
        v[3] = p.get_z();
    }
}

Vector::Vector(double w, const UnitVector &vec) : UnitVector(vec) {
    v[0] = w;
}

Vector::Vector(double x, double y, double z) {
    v[0] = sqrt(pow(x,2) + pow(y,2) + pow(z,2));
    if ( v[0] != 0 ) {
        v[1] = x / v[0];
        v[2] = y / v[0];
        v[3] = z / v[0];
    } else {
        v[1] = x;
        v[2] = y;
        v[3] = z;
    }
}

Vector::Vector(const Vector &vec) : UnitVector(vec) {
    // UnitVector constructor sets up everything for us.
}

Vector::Vector(const UnitVector &vec) : UnitVector(vec) {
    v[0] = 1;
}

}
