/*! \file wip3dmath.h
 * \brief Header file for WIP3DMATH C++ Library.
 */

/* Copyright (c) 2005, 2006 John David Weaver
 * All Rights Reserved.
 */

#if !defined(_WIP3DMATH_H_)
#define _WIP3DMATH_H_

#include <iostream>
#include <cmath>

#define PI 3.14156
#define PIOVER180 0.0174532925
#define PIOVER2 (PI/2.0)

#include "Point/Point.h"
#include "Matrix.h"
#include "MathUtils.h"
#include "Rotation/Rotation.h"
#include "Rotation/Quaternion/Quaternion.h"
#include "Rotation/Euler/Euler.h"
#include "UnitVector/UnitVector.h"
#include "UnitVector/Vector/Vector.h"
#include "Volume/Volume.h"
#include "Volume/Box/Box.h"
#include "Volume/Cylinder/Cylinder.h"
#include "QuadTree/QuadTree.h"
#include "Bezier/BezierSurface/BezierSurface.h"
// OctTree has not been implemented yet.

// XXX for compatibility with older version
using namespace wip3dmath;

#endif /* !defined(_WIP3DMATH_H_) */
