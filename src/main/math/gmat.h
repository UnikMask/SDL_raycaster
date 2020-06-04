#ifndef  GMAT_H
#define GMAT_H

#include "gvec.h"

/* 2D matrix structure */
template <class T> struct gmat
{
	T num_arr[2][2];
};

typedef struct gmat<double> dmat;
typedef struct gmat<int> imat;

/* Matrix to matrix addition*/
template <class T> struct gmat<T> * gmat_add(struct gmat<T> a, gmat<T> b);
template <class T> struct gmat<T> * gmat_sub(struct gmat<T> a, gmat<T> b);
template <class T> struct gmat<T> * gmat_add(struct gmat<T> a, T b);
template <class T> struct gmat<T> * gmat_sub(struct gmat<T> a, T b);
template <class T> struct gmat<T> * gmat_mult(struct gmat<T> a, gmat<T> b);
template <class T> struct gvec<T> * gmat_mult(struct gvec<T> a, gmat<T> b);
template <class T> struct gmat<T> * gmat_bemult(struct gmat<T> a, gmat<T> b);


#endif
