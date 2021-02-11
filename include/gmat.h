/// @file gmat.h

#ifndef  GMAT_H
#define GMAT_H

#pragma once
#include "gvec.h"

/* 2D matrix structure */
template <class T> struct gmat {
	/// Array containing elements of the matrix
	T num_arr[2][2];
	/// Matrix addition operand
	gmat<T> operator + (gmat<T> a);
	/// Matrix and single number addtion operand.
	gmat<T> operator + (T a);
	/// Matrix substraction operand
	gmat<T> operator - (gmat<T> a);
	/// Matrix and single number substraction operand.
	gmat<T> operator - (T a);
	/// Matrix multiplication operand.
	gmat<T> operator * (gmat<T> a);
	/// Matrix and single number multiplication operand.
	gmat<T> operator * (T a);
	/// Matrix and vector multiplication operand.
	gvec<T> operator * (gvec<T> a);
	/// Matrix by-element division operand.
	gmat<T> operator / (gmat<T> a);
	/// Matrix single number division operand.
	gmat<T> operator / (T a);
	/// Matrix equality operand.
	bool operator == (gmat<T> a);
	/// Matrix assignment operand.
	gmat<T> operator = (T a[2][2]);
	/// Constructor for full matrix.
	gmat<T> (T m00, T m01, T m10, T m11);
	/// Constructor for matrix by row vector merging.
	gmat<T> (gvec<T> row0, gvec<T> row1);
	/// Null matrix constructor.
	gmat<T> (void);
};


/// Matrix of doubles.
typedef struct gmat<double> dmat;
/// Matrix of integers.
typedef struct gmat<int> imat;

/**
 * Multiply a vector and a matrix together.
 * @param a Row vector oh lhs.
 * @param b Matrix on lhs.
 * @return Resulting product.
 */
template<class T> gvec<T> operator * (struct gvec<T> a, struct gmat<T> b);

/**
 * Add two matrices together.
 * @param a lhs matrix.
 * @param b rhs matrix.
 * @return Resulting matrix addition.
 */
template <class T> struct gmat<T> gmat_add(struct gmat<T> a, struct gmat<T> b) {
	struct gmat<T> c;
	// Loop on multiplied lengths of num_arr's rows and columns.
	for (size_t row = 0; row < sizeof(c.num_arr) / sizeof(c.num_arr[0]); row++)
		for (size_t col = 0; col < sizeof(c.num_arr[0]) / sizeof(T); col++) {
			c.num_arr[row][col] = a.num_arr[row][col] + b.num_arr[row][col];
		}
	return  c;
}

/**
 * Add a single number to all elements of a matrix.
 * @param a Matrix to add to.
 * @param b Number to add to a.
 * @return Resulting addition.
 */
template <class T> struct gmat<T> gmat_add(struct gmat<T> a, T b) {
	struct gmat<T> c;
	// Loop on multiplied lengths of num_arr's rows and columns.
	for (size_t row = 0; row < sizeof(c.num_arr) / sizeof(c.num_arr[0]); row++)
		for (size_t col = 0; col < sizeof(c.num_arr[0]) / sizeof(T); col++) {
			c.num_arr[row][col] = a.num_arr[row][col] + b;
		}
	return  c;
}

/**
 * Matrix to matrix multiplication.
 * @param a lhs matrix.
 * @param b rhs matrix.
 * @return resulting product.
 */
template <class T> struct gmat<T> gmat_mult(struct gmat<T> a, struct gmat<T> b) {
	struct gmat<T> c;
	// Loop on multiplied lengths of num_arr's rows and columns.
	for (size_t i = 0; i < sizeof(c.num_arr) / sizeof(c.num_arr[0]); i++)
		for (size_t j = 0; j < sizeof(c.num_arr[0]) / sizeof(T); j++)
			for (int n = 0; n < sizeof(a.num_arr) / sizeof(*a.num_arr); n++) {
				c.num_arr[i][j] += a.num_arr[i][n] * b.num_arr[n][j];
			}
	return  c;
}

/**
 * Matrix and single number multiplication.
 * @param a target matrix.
 * @param b multiplying factor.
 * @return Resulting product.
 */
template <class T> struct gmat<T> gmat_mult(struct gmat<T> a, T b) {
	gmat<T> res;
	for (int i = 0; i < sizeof(a.num_arr) / sizeof(a.num_arr[0]); i++) {
		for (int j = 0; j < sizeof(a.num_arr[0]) / sizeof(T); j++) {
			res.num_arr[i][j] = b * a.num_arr[i][j];
		}
	}
	return res;
}

/**
 * Multiply row vector with matrix.
 * @param a lhs vector.
 * @param b rhs matrix.
 * @return Resulting product.
 */
template <class T> struct gvec<T> gmat_mult(struct gvec<T> a, struct gmat<T> b) {
	struct gvec<T> c;
	for (int i = 0; i < sizeof(c.num_arr) / sizeof(T); i++) {
		for (int j = 0; j < sizeof(a.num_arr) / sizeof(T); j++)
			c.num_arr[i] += a.num_arr[j] * b.num_arr[j][i];
	}
	return c;
}

/**
 * Multiply a matrix with a column vector.
 * @param a lhs matrix.
 * @param b rhs column vector.
 * @return Resulting product.
 */
template <class T> struct gvec<T> gmat_mult(struct gmat<T> a, struct gvec<T> b) {
	struct gvec<T> c;
	for (int i = 0; i < sizeof(c.num_arr) / sizeof(T); i++) {
		c.num_arr[i] = 0;
		for (int j = 0; j < sizeof(b.num_arr) / sizeof(T); j++)
			c.num_arr[i] += a.num_arr[i][j] * b.num_arr[j];
	}
	return c;
}

/**
 * Perform scalar (by-element) matrix multiplication.
 * @param a 1st matrix.
 * @param b 2nd matrix.
 * @return Resulting product.
 */
template <class T> struct gmat<T> gmat_bemult(struct gmat<T> a, struct gmat<T> b) {
	struct gmat<T> c;
	// Loop on multiplied lengths of num_arr's rows and columns.
	for (size_t row = 0; row < sizeof(c.num_arr) / sizeof(c.num_arr[0]); row++)
		for (size_t col = 0; col < sizeof(c.num_arr[0]) / sizeof(T); col++) {
			c.num_arr[row][col] = a.num_arr[row][col] * b.num_arr[row][col];
		}
	return  c;
}

/**
 * Checks whether two matrices are equal.
 * @param a First matrix.
 * @param b Second matrix.
 * @return The equality's status.
 */
template <class T> bool gmat_eq(struct gmat<T> a, struct gmat<T> b) {
	return ( a.num_arr[0][0] == b.num_arr[0][0] && a.num_arr[0][1] == b.num_arr[0][1] &&
			 a.num_arr[1][0] == b.num_arr[1][0] && a.num_arr[1][1] == b.num_arr[1][1]);
}

/**
 * Assign a matrix a new value.
 * @param a The matrix to modify.
 * @param new_arr The new array to assign to the matrix.
 */
template <class T> void gmat_assign (gmat<T>* a, T new_arr[2][2]) {
	for (size_t i = 0; i < 2; i++)
		for (size_t j = 0; j < 2; j++)
		{
			a->num_arr[i][j] = new_arr[i][j];
		}
}


/* gmat struct methods forward declaration*/
template <class T> gmat<T>::gmat(T m00, T m01, T m10, T m11) {
	this->num_arr[0][0]=m00;
	this->num_arr[0][1]=m01;
	this->num_arr[1][0]=m10;
	this->num_arr[1][1]=m11;
}
template <class T> gmat<T>::gmat(gvec<T> row0, gvec<T> row1) {
	for (size_t i = 0; i < 2; i++) {
		this->num_arr[0][i] = row0.num_arr[i];
		this->num_arr[1][i] = row1.num_arr[i];
	}
}
template <class T> gmat<T>::gmat(void) {
	for (size_t i = 0; i < sizeof(this->num_arr) / sizeof(this->num_arr[0]); i++)
		for (size_t j = 0; j < sizeof(this->num_arr[0]) / sizeof(T); j++) {
			this->num_arr[i][j] = 0;
		}
}
template <class T> gmat<T> gmat<T>::operator + (gmat<T> a) {
	return gmat_add(*this, a);
}
template <class T> gmat<T> gmat<T>::operator - (gmat<T> a) {
	return gmat_add(*this, a * (-1));
}
template <class T> gmat<T> gmat<T>::operator + (T a) {
	return gmat_add(*this, a);
}
template <class T> gmat<T> gmat<T>::operator - (T a) {
	return gmat_add(*this, a * (-1));
}
template <class T> gmat<T> gmat<T>::operator * (gmat<T> a) {
	return gmat_mult(*this, a);
}
template <class T> gvec<T> gmat<T>::operator * (gvec<T> a) {
	return gmat_mult(*this, a);
}
template <class T> gmat<T> gmat<T>::operator * (T a) {
	return gmat_mult(*this, a);
}
template <class T> gvec<T> operator * (struct gvec<T> a, struct gmat<T> b) {
	return gmat_mult(a, b);
}
template <class T> bool gmat<T>::operator == (gmat<T> a) {
	return gmat_eq(*this, a);
}
template <class T> gmat<T> gmat<T>::operator = (T a[2][2]) {
	gmat<T> ret_mat;
	ret_mat.num_arr = a;
	return ret_mat;
}
#endif
