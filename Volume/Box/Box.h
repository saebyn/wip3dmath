/*! \file Box.h
 * \brief Header file for Box.cc.
 */

/* Copyright (c) 2005, 2006 John David Weaver
 * All Rights Reserved.
 */

#if !defined(_WIP3DMATH_POINT_POINT3D_VECTOR_VOLUME_BOX_BOX_H_)
#define _WIP3DMATH_POINT_POINT3D_VECTOR_VOLUME_BOX_BOX_H_

namespace wip3dmath {

//! Box class.
/*! Provides a datatype representing a Box.
 */
class Box : public Volume {
 public:
    /* some basic things first */
    double* get(double*) const;
    /* some usful methods */
    bool inVolume(Point &);
    double distance(Point &);
    /* Constructors */
    Box(const Box &);
    Box(const Point &, double xlength, double ylength, double zlength);
    Box(double x, double y, double z, double xlength, double ylength, double zlength);
 private:
    double xhalfwidth, yhalfwidth, zhalfwidth;
};

};

#endif /* !defined(_WIP3DMATH_VOLUME_BOX_BOX_H_) */
