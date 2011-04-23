/*! \file Volume.h
 * \brief Header file for Volume.cc.
 */

/* Copyright (c) 2006 John David Weaver
 * All Rights Reserved.
 */

#if !defined(_WIP3DMATH_POINT_POINT3D_VECTOR_VOLUME_VOLUME_H_)
#define _WIP3DMATH_POINT_POINT3D_VECTOR_VOLUME_VOLUME_H_

namespace wip3dmath {

//! Volume class.
/*! Provides an abstract datatype representing a Volume.
 */
class Volume : public Point {
 public:
    Volume() : Point(0,0,0) {}
    /* some usful methods */
    virtual bool inVolume(Point &) = 0;
    virtual double distance(Point &) = 0;
};

};

#endif /* !defined(_WIP3DMATH_POINT_POINT3D_VECTOR_VOLUME_VOLUME_H_) */
