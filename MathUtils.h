/*! \file MathUtils.h
 * \brief Header file for MathUtils.cc.
 */

/* Copyright (c) 2005 John David Weaver
 * All Rights Reserved.
 */

#if !defined(_WIP3DMATH_MATHUTILS_H_)
#define _WIP3DMATH_MATHUTILS_H_
namespace wip3dmath {
    namespace MathUtils {
        double dotProduct3(double x1, double y1, double z1, 
                           double x2, double y2, double z2);
        void crossProduct3(double x1, double y1, double z1,
                           double x2, double y2, double z2,
                           double *rx, double *ry, double *rz);
    }
}
#endif /* !defined(_WIP3DMATH_MATHUTILS_H_) */
