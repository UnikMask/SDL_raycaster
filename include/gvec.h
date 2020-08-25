#ifndef  GVEC_H
#define GVEC_H
#include <vector>


template <class T>
/* 2D vector structure */
struct gvec
{
	T num_arr[2];
	gvec<T> operator + (gvec<T> a);
	gvec<T> operator - (gvec<T> a);
	gvec<T> operator + (T a);
	gvec<T> operator - (T a);
	T operator * (gvec<T> a);
	gvec<T> operator * (T a);
	bool operator == (gvec<T> a); // Equality
	bool operator == (T a[2]);
	gvec<T> operator = (T a[2]); // 
	gvec<T> (T a, T b); // Constructor
};

typedef gvec<double> dvec;
typedef gvec<int> ivec;


/* Vector to vector addition */
template <class T> gvec<T> gvec_add(struct gvec<T> a, struct gvec<T> b);
/* Vector to vector substraction */
template <class T> gvec<T> gvec_sub(struct gvec<T> a, struct gvec<T> b);
/* Vector to raw type addition */
template <class T> gvec<T> gvec_add(struct gvec<T> a, T b);
/* Vector to raw type substraction */
template <class T> gvec<T> gvec_sub(struct gvec<T> a, T b);
/* Vector by constant multiplication*/
template <class T> gvec<T> gvec_mult(struct gvec<T> a, T b);
/* Vector scalar multiplication */
template <class T> T gvec_mult(struct gvec<T> a, struct gvec<T> b);
/* Vector by-element multiplication */
template <class T> gvec<T> gvec_bemult(struct gvec<T> a, struct gvec<T> b);
/* Vector equality*/
template <class T> bool gvec_eq(gvec<T> a, gvec<T> b);

#endif
