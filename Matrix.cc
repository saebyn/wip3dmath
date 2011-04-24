/*! \file Matrix.cc
 * \brief Matrix class.
 */

/* Copyright (c) 2005 John David Weaver
 * All Rights Reserved.
 */

#include "wip3dmath.h" 

#include <cstring>

namespace wip3dmath {

/* some basic things first */
double *
Matrix::get(double *array) const
{
    array[0] = _11;
    array[1] = _21;
    array[2] = _31;
    array[3] = _41;

    array[4] = _12;
    array[5] = _22;
    array[6] = _32;
    array[7] = _42;

    array[8] = _13;
    array[9] = _23;
    array[10] = _33;
    array[11] = _43;

    array[12] = _14;
    array[13] = _24;
    array[14] = _34;
    array[15] = _44;
    
    return array;
}

void 
Matrix::set(double *array) 
{
    _11 = array[0];
    _21 = array[1];
    _31 = array[2];
    _41 = array[3];

    _12 = array[4];
    _22 = array[5];
    _32 = array[6];
    _42 = array[7];

    _13 = array[8];
    _23 = array[9];
    _33 = array[10];
    _43 = array[11];

    _14 = array[12];
    _24 = array[13];
    _34 = array[14];
    _44 = array[15];
}

void
Matrix::identity(void)
{
    _11 = 1 ; _12 = 0 ; _13 = 0 ; _14 = 0;
    _21 = 0 ; _22 = 1 ; _23 = 0 ; _24 = 0;
    _31 = 0 ; _32 = 0 ; _33 = 1 ; _34 = 0;
    _41 = 0 ; _42 = 0 ; _43 = 0 ; _44 = 1;
}

/* basic math operators */
Matrix 
Matrix::operator* (const Matrix &value) const 
{
    // This uses column-major order (the same as OpenGL).
    // the internal _[1-4][1-4] doubles are numbered _[row][column].
    double pA[16]={_11,_21,_31,_41,_12,_22,_32,_42,_13,_23,_33,_43,_14,_24,_34,_44};
    double pB[16]={value._11,value._21,value._31,value._41,
                   value._12,value._22,value._32,value._42,
                   value._13,value._23,value._33,value._43,
                   value._14,value._24,value._34,value._44};
    double *pM = new double[16];

    memset(pM, 0, 16*sizeof(double));

    for(int i=0; i<4; i++) 
       for(int j=0; j<4; j++) {
           pM[4*j+i] += pA[4*j]   * pB[i];
           pM[4*j+i] += pA[4*j+1] * pB[4+i];
           pM[4*j+i] += pA[4*j+2] * pB[8+i];
           pM[4*j+i] += pA[4*j+3] * pB[12+i];
       }

    Matrix result(pM);

    delete [] pM;

    return result;
}

Point
Matrix::operator* (const Point& value) const
{
    Point result;
    double rx, ry, rz, rw;
    double x, y, z;
    x = value.get_x(); y = value.get_y(); z = value.get_z();

    rx = _11*x + _21*y + _31*z + _41;
    ry = _12*x + _22*y + _32*z + _42;
    rz = _13*x + _23*y + _33*z + _43;
    rw = _14*x + _24*y + _34*z + _44;

    result.set(rx/rw, ry/rw, rz/rw);

    return result;
}

/* Matrix math methods */
void
Matrix::transpose(void)
{
    double copy;

    copy = _21;
    _21 = _12;
    _12 = copy;

    copy = _31;
    _31 = _13;
    _13 = copy;

    copy = _41;
    _41 = _14;
    _14 = copy;

    copy = _32;
    _32 = _23;
    _23 = copy;

    copy = _42;
    _42 = _24;
    _24 = copy;

    copy = _43;
    _43 = _34;
    _34 = copy;

}

/* Rotation methods */

/* Translation methods */


/* Constructors */

Matrix::Matrix(const Matrix &value)
{
    *this = value;
}

Matrix::Matrix(double *array) {
    set(array);
}

Matrix::Matrix(void)
{
    identity();
}

}
