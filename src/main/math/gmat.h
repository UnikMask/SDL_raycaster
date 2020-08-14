#ifndef  GMAT_H
#define GMAT_H

#pragma once
#include "gvec.h"

/* 2D matrix structure */
template <class T> struct gmat
{
	T num_arr[2][2];
	gmat<T> operator + (gmat<T> a);
	gmat<T> operator - (gmat<T> a);
	gmat<T> operator + (T a);
	gmat<T> operator - (T a);
	gmat<T> operator * (gmat<T> a);
	gmat<T> operator * (T a);
	gvec<T> operator * (gvec<T> a);
	gmat<T> operator / (gmat<T> a);
	gmat<T> operator / (T a);
	bool operator == (gmat<T> a);
	gmat<T> (T m00, T m01, T m10, T m11);
	gmat<T> (gvec<T> row0, gvec<T> row1);
};


typedef struct gmat<double> dmat;
typedef struct gmat<int> imat;

/* Extra vector to matrix multiplication operator */
template<class T> gvec<T> operator * (struct gvec<T> a, struct gmat<T> b);

/* Matrix to matrix addition */
template <class T> struct gmat<T> gmat_add(struct gmat<T> a, struct gmat<T> b);
/* Matrix to matrix substraction */
template <class T> struct gmat<T> gmat_sub(struct gmat<T> a, struct gmat<T> b);
/* Matrix to constant addition */
template <class T> struct gmat<T> gmat_add(struct gmat<T> a, T b);
/* Matrix to constant substraction */
template <class T> struct gmat<T> gmat_sub(struct gmat<T> a, T b);
/* Matrix to matrix multiplication */
template <class T> struct gmat<T> gmat_mult(struct gmat<T> a, struct gmat<T> b);
/* Vector to matrix multiplication */
template <class T> struct gvec<T> gmat_mult(struct gvec<T> a, struct gmat<T> b);
/* Matrix to vector multiplication */
template <class T> struct gvec<T> gmat_mult(struct gmat<T> a, struct gvec<T> b);
/* Matrix to matrix by-element multiplication */
template <class T> struct gmat<T> gmat_bemult(struct gmat<T> a, struct gmat<T> b);
/* Matrix equality */
template <class T> bool gmat_eq(struct gmat<T> a, struct gmat<T> b);


#endif
