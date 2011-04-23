/*! \file BezierSurface.h
 * \brief Header file for abstract class BezierSurface.
 */

/* Copyright (c) 2006 John David Weaver
 * All Rights Reserved.
 */

#if !defined(_WIP3DMATH_BEZIER_BEZIERSURFACE_BEZIERSURFACE_H_)
#define _WIP3DMATH_BEZIER_BEZIERSURFACE_BEZIERSURFACE_H_

namespace wip3dmath {

class Point;

//! BezierSurface class.
/*! Provides a abstract datatype representing a 4x4 control point bezier surface.
 */
class BezierSurface {
 public:
    BezierSurface(Point ctlpoints[16]);
    void getPoints(Point *points, int num_points); // num_points is size of buffer
                                                     // pointed to by points.
                                                     // getPoints will generate as
                                                     // much detail as possible to 
                                                     // fill points.
    Point getPoint(double a, double c);
    void getNormals(Point *normals, int num_normals); // this will generate a normal
                                                        // for each point, provided that
                                                        // num_normals == num_points.
 private:
    double Ax, Ay, Az;
    double Bx, By, Bz;
    double Cx, Cy, Cz;
    double Dx, Dy, Dz;
    double Ex, Ey, Ez;
    double Fx, Fy, Fz;
    double Gx, Gy, Gz;
    double Hx, Hy, Hz;
    double Ix, Iy, Iz;
    double Jx, Jy, Jz;
    double Kx, Ky, Kz;
    double Lx, Ly, Lz;
    double Mx, My, Mz;
    double Nx, Ny, Nz;
    double Ox, Oy, Oz;
    double Px, Py, Pz;
};

}; // namespace wip3dmath

#endif /* !defined(_WIP3DMATH_BEZIER_BEZIERSURFACE_BEZIERSURFACE_H_) */
