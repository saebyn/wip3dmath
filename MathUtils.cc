/*! \file MathUtils.cc
 * \brief Code for various operations.
 */

/* Copyright (c) 2005 John David Weaver
 * All Rights Reserved.
 */

#include "wip3dmath.h"

//! dotProduct3 function.
/*!
 \param x1 First element of first 3x1 matrix.
 \param y1 Second element of first 3x1 matrix.
 \param z1 Third element of first 3x1 matrix.
 \param x2 First element of second 3x1 matrix.
 \param y2 Second element of second 3x1 matrix.
 \param z2 Third element of second 3x1 matrix.
 \return Dot product of matrices.
 */
double
MathUtils::dotProduct3(double x1, double y1, double z1,
                       double x2, double y2, double z2)
{
	return(x1*x2 + y1*y2 + z1*z2);
}

//! crossProduct3 function.
/*!
 \param x1 First element of first 3x1 matrix.
 \param y1 Second element of first 3x1 matrix.
 \param z1 Third element of first 3x1 matrix.
 \param x2 First element of second 3x1 matrix.
 \param y2 Second element of second 3x1 matrix.
 \param z2 Third element of second 3x1 matrix.
 \param rx Pointer to store first result element.
 \param ry Pointer to store second result element.
 \param rz Pointer to store third result element.
 */
void
MathUtils::crossProduct3(double x1, double y1, double z1,
                         double x2, double y2, double z2,
                         double *rx, double *ry, double *rz)
{
	*rx = y1*z2 - z1*y2;
	*ry = z1*x2 - x1*z2;
	*rz = x1*y2 - y1*x2;
}
