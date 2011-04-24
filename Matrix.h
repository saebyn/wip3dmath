/*! \file Matrix.h
 * \brief Header file for Matrix.cc.
 */

/* Copyright (c) 2005 John David Weaver
 * All Rights Reserved.
 */

#if !defined(_WIP3DMATH_MATRIX_H_)
#define _WIP3DMATH_MATRIX_H_

namespace wip3dmath {

//! Matrix class.
/*! Provides a datatype representing a 4x4 Matrix.
 */
class Matrix {
 public:
    /* some basic things first */
    double* get(double*) const;
    void set(double *);
    void identity();
    /* basic math operators */
    Matrix operator* (const Matrix &) const;
    Point operator* (const Point &) const;
    /* Matrix math methods */
    void transpose(void);
    /* Rotation methods */
    /*Matrix& rotate(double xrot, double yrot, double zrot);
    Matrix& rotate(const Quaternion&);
    Matrix& rotate(double xrot, double yrot, double zrot, const Point&);
    Matrix& rotate(const Quaternion&, const Point&);*/
    /* Translation methods */
    //Matrix& translate(const Point&);
    /* Constructors */
    Matrix(const Matrix &);
    Matrix(double *);
    Matrix(void);
 protected:
    double _11, _12, _13, _14;
    double _21, _22, _23, _24;
    double _31, _32, _33, _34;
    double _41, _42, _43, _44;

    /* I/O methods */
    friend std::ostream& operator<< (std::ostream&, Matrix);
};

}

#endif /* !defined(_WIP3DMATH_MATRIX_H_) */
