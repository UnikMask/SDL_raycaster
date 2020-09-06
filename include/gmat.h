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
	gmat<T> operator = (T a[2][2]);
	gmat<T> (T m00, T m01, T m10, T m11);
	gmat<T> (gvec<T> row0, gvec<T> row1);
	gmat<T> (void);
};


typedef struct gmat<double> dmat;
typedef struct gmat<int> imat;

/* Extra vector to matrix multiplication operator */
template<class T> gvec<T> operator * (struct gvec<T> a, struct gmat<T> b);

/* Matrix to matrix addition */
template <class T> struct gmat<T> gmat_add(struct gmat<T> a, struct gmat<T> b)
{
	struct gmat<T> c;
	// Loop on multiplied lengths of num_arr's rows and columns.
	for (size_t row = 0; row < sizeof(c.num_arr) / sizeof(c.num_arr[0]); row++)
		for (size_t col = 0; col < sizeof(c.num_arr[0]) / sizeof(T); col++)
		{
			c.num_arr[row][col] = a.num_arr[row][col] + b.num_arr[row][col];
		}
	return  c;
}
/* Matrix to matrix substraction */
template <class T> struct gmat<T> gmat_sub(struct gmat<T> a, struct gmat<T> b)
{
	struct gmat<T> c;
	// Loop on multiplied lengths of num_arr's rows and columns.
	for (size_t row = 0; row < sizeof(c.num_arr) / sizeof(c.num_arr[0]); row++)
		for (size_t col = 0; col < sizeof(c.num_arr[0]) / sizeof(T); col++)
		{
			c.num_arr[row][col] = a.num_arr[row][col] - b.num_arr[row][col];
		}
	return  c;
}
/* Matrix to constant addition */
template <class T> struct gmat<T> gmat_add(struct gmat<T> a, T b)
{
	struct gmat<T> c;
	// Loop on multiplied lengths of num_arr's rows and columns.
	for (size_t row = 0; row < sizeof(c.num_arr) / sizeof(c.num_arr[0]); row++)
		for (size_t col = 0; col < sizeof(c.num_arr[0]) / sizeof(T); col++)
		{
			c.num_arr[row][col] = a.num_arr[row][col] + b;
		}
	return  c;
}
/* Matrix to constant substraction */
template <class T> struct gmat<T> gmat_sub(struct gmat<T> a, T b)
{
	struct gmat<T> c;
	// Loop on multiplied lengths of num_arr's rows and columns.
	for (size_t row = 0; row < sizeof(c.num_arr) / sizeof(c.num_arr[0]); row++)
		for (size_t col = 0; col < sizeof(c.num_arr[0]) / sizeof(T); col++)
		{
			c.num_arr[row][col] = a.num_arr[row][col] - b;
		}
	return  c;
}
/* Matrix to matrix multiplication */
template <class T> struct gmat<T> gmat_mult(struct gmat<T> a, struct gmat<T> b)
{
	struct gmat<T> c;
	// Loop on multiplied lengths of num_arr's rows and columns.
	for (size_t row = 0; row < sizeof(c.num_arr) / sizeof(c.num_arr[0]); row++)
		for (size_t col = 0; col < sizeof(c.num_arr[0]) / sizeof(T); col++)
		{
			c.num_arr[row][col] = 0;
			for (int n = 0; n < sizeof(a.num_arr) / sizeof(*a.num_arr); n++) 
			{
				c.num_arr[row][col] += a.num_arr[row][n] * b.num_arr[n][col];
			}
		}
	return  c;
}
/* Vector to matrix multiplication */
template <class T> struct gvec<T> gmat_mult(struct gvec<T> a, struct gmat<T> b)
{
	struct gvec<T> c;
	for (int i = 0; i < sizeof(c.num_arr) / sizeof(T); i++)
	{
		for (int n = 0; n < sizeof(a.num_arr) / sizeof(T); n++)
			c.num_arr[i] += a.num_arr[n] * b.num_arr[n][i];
	}
	return c;
}
/* Matrix to vector multiplication */
template <class T> struct gvec<T> gmat_mult(struct gmat<T> a, struct gvec<T> b)
{
	struct gvec<T> c;
	for (int i = 0; i < sizeof(c.num_arr) / sizeof(T); i++)
	{
		c.num_arr[i] = 0;
		for (int n = 0; n < sizeof(b.num_arr) / sizeof(T); n++)
			c.num_arr[i] += a.num_arr[i][n] * b.num_arr[n]; 
	}
	return c;
}
/* Matrix to matrix by-element multiplication */
template <class T> struct gmat<T> gmat_bemult(struct gmat<T> a, struct gmat<T> b)
{
	struct gmat<T> c;
	// Loop on multiplied lengths of num_arr's rows and columns.
	for (size_t row = 0; row < sizeof(c.num_arr) / sizeof(c.num_arr[0]); row++)
		for (size_t col = 0; col < sizeof(c.num_arr[0]) / sizeof(T); col++)
		{
			c.num_arr[row][col] = a.num_arr[row][col] * b.num_arr[row][col];
		}
	return  c;
}
/* Matrix equality */
template <class T> bool gmat_eq(struct gmat<T> a, struct gmat<T> b)
{
	return ( a.num_arr[0][0] == b.num_arr[0][0] && a.num_arr[0][1] == b.num_arr[0][1] &&
			 a.num_arr[1][0] == b.num_arr[1][0] && a.num_arr[1][1] == b.num_arr[1][1]);
}
/* Matrix assignment */
template <class T> void gmat_assign (gmat<T>* a, T new_arr[2][2])
{
	for (size_t i = 0; i < 2; i++)
		for (size_t j = 0; j < 2; j++)
		{
			a->num_arr[i][j] = new_arr[i][j];
		}
}


/* gmat struct methods forward declaration*/
template <class T> gmat<T>::gmat(T m00, T m01, T m10, T m11)
{
	this->num_arr[0][0]=m00;
	this->num_arr[0][1]=m01;
	this->num_arr[1][0]=m10;
	this->num_arr[1][1]=m11;
}
template <class T> gmat<T>::gmat(gvec<T> row0, gvec<T> row1)
{
	for (size_t i = 0; i < 2; i++)
	{
		this->num_arr[0][i] = row0.num_arr[i];
		this->num_arr[1][i] = row1.num_arr[i];
	}
}
template <class T> gmat<T>::gmat(void)
{
	for (size_t i = 0; i < sizeof(this->num_arr) / sizeof(this->num_arr[0]); i++)
		for (size_t j = 0; j < sizeof(this->num_arr[0]) / sizeof(T); j++)
		{
			this->num_arr[i][j] = 0;
		}
}
template <class T> gmat<T> gmat<T>::operator + (gmat<T> a)
{
	return gmat_add(*this, a);
}
template <class T> gmat<T> gmat<T>::operator - (gmat<T> a)
{
	return gmat_sub(*this, a);
}
template <class T> gmat<T> gmat<T>::operator + (T a)
{
	return gmat_add(*this, a);
}
template <class T> gmat<T> gmat<T>::operator - (T a)
{
	return gmat_sub(*this, a);
}
template <class T> gmat<T> gmat<T>::operator * (gmat<T> a)
{
	return gmat_mult(*this, a);
}
template <class T> gvec<T> gmat<T>::operator * (gvec<T> a)
{
	return gmat_mult(*this, a);
}
template <class T> gmat<T> gmat<T>::operator * (T a)
{
	return gmat_mult(*this, a);
}
template <class T> gvec<T> operator * (struct gvec<T> a, struct gmat<T> b)
{
	return gmat_mult(a, b);
}
template <class T> bool gmat<T>::operator == (gmat<T> a)
{
	return gmat_eq(*this, a);
}
template <class T> gmat<T> gmat<T>::operator = (T a[2][2])
{
	gmat<T> ret_mat;
	ret_mat.num_arr = a;
	return ret_mat;
}
#endif
