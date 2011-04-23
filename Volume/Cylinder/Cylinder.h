/*! \file Cylinder.h
 * \brief Header file for Cylinder.cc.
 */

/* Copyright (c) 2006 John David Weaver
 * All Rights Reserved.
 */

#if !defined(_WIP3DMATH_POINT_POINT3D_VECTOR_VOLUME_CYLINDER_CYLINDER_H_)
#define _WIP3DMATH_POINT_POINT3D_VECTOR_VOLUME_CYLINDER_CYLINDER_H_

namespace wip3dmath {

//! Cylinder class.
/*! Provides a datatype representing a Cylinder with major axis along Y axis.
 */
class Cylinder : public Volume {
 public:
    /* some basic things first */
    double* get(double*) const;
    /* some usful methods */
    bool inVolume(Point &);
    double distance(Point &);
    /* Constructors */
    Cylinder();
    Cylinder(const Cylinder &);
    Cylinder(const Point &, double radius, double height);
    Cylinder(double x, double y, double z, double radius, double height);
 protected:
    double radius, height;
};

};

#endif /* !defined(_WIP3DMATH_POINT_POINT3D_VECTOR_VOLUME_CYLINDER_CYLINDER_H_) */
