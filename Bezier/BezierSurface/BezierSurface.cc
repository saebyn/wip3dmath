/*! \file BezierSurface.cc
 * \brief BezierSurface class.
 */

/* Copyright (c) 2006 John David Weaver
 * All Rights Reserved.
 */

#include "wip3dmath.h" 

#include <cmath>

namespace wip3dmath {

BezierSurface::BezierSurface(Point ctlpoints[16]) {
    ctlpoints[0].get(Ax, Ay, Az);
    ctlpoints[1].get(Bx, By, Bz);
    ctlpoints[2].get(Cx, Cy, Cz);
    ctlpoints[3].get(Dx, Dy, Dz);
    ctlpoints[4].get(Ex, Ey, Ez);
    ctlpoints[5].get(Fx, Fy, Fz);
    ctlpoints[6].get(Gx, Gy, Gz);
    ctlpoints[7].get(Hx, Hy, Hz);
    ctlpoints[8].get(Ix, Iy, Iz);
    ctlpoints[9].get(Jx, Jy, Jz);
    ctlpoints[10].get(Kx, Ky, Kz);
    ctlpoints[11].get(Lx, Ly, Lz);
    ctlpoints[12].get(Mx, My, Mz);
    ctlpoints[13].get(Nx, Ny, Nz);
    ctlpoints[14].get(Ox, Oy, Oz);
    ctlpoints[15].get(Px, Py, Pz);
}

void 
BezierSurface::getPoints(Point *points, int num_points) {
    int num_quads = num_points / 4;
    double quadsidelen = sqrt( 1.0 / (double)num_quads );
    int nPoint = 0;

    for ( double a = 0.0; a <= 1.0; a += quadsidelen ) {
        for ( double c = 0.0; c <= 1.0; nPoint+=4) {
            points[nPoint]   = getPoint(a,c);
            a += quadsidelen;
            points[nPoint+1] = getPoint(a,c);
            c += quadsidelen;
            points[nPoint+2] = getPoint(a,c);
            a -= quadsidelen;
            points[nPoint+3] = getPoint(a,c);
        }
    }
}

Point 
BezierSurface::getPoint(double a, double c) {
    double x, y, z;
    double b = 1.0-a;
    double d = 1.0-c;

    x = Ax*a*a*a*c*c*c     + Bx*3.0*a*a*a*c*c*d + Cx*3.0*a*a*a*c*d*d + Dx*a*a*a*d*d*d + \
        Ex*3.0*a*a*b*c*c*c + Fx*9.0*a*a*b*c*c*d + Gx*9.0*a*a*b*c*d*d + Hx*3.0*a*a*b*d*d*d + \
        Ix*3.0*a*b*b*c*c*c + Jx*9.0*a*c*c*b*b*d + Kx*9.0*a*b*b*c*d*d + Lx*3.0*a*b*b*d*d*d + \
        Mx*b*b*b*c*c*c     + Nx*3.0*b*b*b*c*c*d + Ox*3.0*b*b*b*c*d*d + Px*b*b*b*d*d*d;

    y = Ay*a*a*a*c*c*c     + By*3.0*a*a*a*c*c*d + Cy*3.0*a*a*a*c*d*d + Dy*a*a*a*d*d*d + \
        Ey*3.0*a*a*b*c*c*c + Fy*9.0*a*a*b*c*c*d + Gy*9.0*a*a*b*c*d*d + Hy*3.0*a*a*b*d*d*d + \
        Iy*3.0*a*b*b*c*c*c + Jy*9.0*a*c*c*b*b*d + Ky*9.0*a*b*b*c*d*d + Ly*3.0*a*b*b*d*d*d + \
        My*b*b*b*c*c*c     + Ny*3.0*b*b*b*c*c*d + Oy*3.0*b*b*b*c*d*d + Py*b*b*b*d*d*d;

    z = Az*a*a*a*c*c*c     + Bz*3.0*a*a*a*c*c*d + Cz*3.0*a*a*a*c*d*d + Dz*a*a*a*d*d*d + \
        Ez*3.0*a*a*b*c*c*c + Fz*9.0*a*a*b*c*c*d + Gz*9.0*a*a*b*c*d*d + Hz*3.0*a*a*b*d*d*d + \
        Iz*3.0*a*b*b*c*c*c + Jz*9.0*a*c*c*b*b*d + Kz*9.0*a*b*b*c*d*d + Lz*3.0*a*b*b*d*d*d + \
        Mz*b*b*b*c*c*c     + Nz*3.0*b*b*b*c*c*d + Oz*3.0*b*b*b*c*d*d + Pz*b*b*b*d*d*d;

    return Point(x,y,z);
}

void 
BezierSurface::getNormals(Point *normals, int num_normals) {
}

};
