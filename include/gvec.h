#ifndef  GVEC_H
#define GVEC_H
#include <vector>


template <class T>
/* 2D vector structure */
struct gvec
{
	public:
	T num_arr[2];
	gvec<T> operator + (gvec<T> a); // Vector and vector additon
	gvec<T> operator - (gvec<T> a); // Vector and vector substraction
	gvec<T> operator + (T a); // Vector and primitive addition {
	gvec<T> operator - (T a); // Vector and primitive substraction
	T operator * (gvec<T> a); // Dot product
	gvec<T> operator * (T a); // Vector and primitive multiplication
	bool operator == (const gvec<T> a); // Vector to vector Equality
	bool operator == (const T a[2]); // Vector to array equality
	gvec<T> (T a, T b); // Constructor
	gvec<T> ();
};

typedef gvec<double> dvec;
typedef gvec<int> ivec;


/* Vector to vector addition */
template <class T> gvec<T> gvec_add(struct gvec<T> a, struct gvec<T> b)
{
	return gvec<T> (a.num_arr[0] + b.num_arr[0], 
			a.num_arr[1] + b.num_arr[1]);
}
/* Vector to vector substraction */
template <class T> gvec<T> gvec_sub(struct gvec<T> a, struct gvec<T> b)
{
	return gvec<T> (a.num_arr[0] - b.num_arr[0],
			a.num_arr[1] - b.num_arr[1]);
}
/* Vector to raw type addition */
template <class T> gvec<T> gvec_add(struct gvec<T> a, T b)
{ 
	struct gvec<T> c (0, 0);
	for (int i = 0; i < sizeof(c.num_arr) / sizeof(*c.num_arr); i++)
	{
		c.num_arr[i] = a.num_arr[i] + b;
	}
	return c;
}
/* Vector to raw type substraction */
template <class T> gvec<T> gvec_sub(struct gvec<T> a, T b)
{
	struct gvec<T> c (a.num_arr[0], a.num_arr[1]);
	for (int i = 0; i < sizeof(c.num_arr) / sizeof(*c.num_arr); i++)
		c.num_arr[i] -= b;
	return c;
}
/* Vector by constant multiplication*/
template <class T> gvec<T> gvec_mult(struct gvec<T> a, T b)
{
	struct gvec<T> c (a.num_arr[0], a.num_arr[1]);
	for (int i = 0; i < sizeof(c.num_arr) / sizeof(*c.num_arr); i++)
		c.num_arr[i] *= b;
	return c;
}
/* Vector scalar multiplication */
template <class T> T gvec_mult(struct gvec<T> a, struct gvec<T> b)
{
	return a.num_arr[0] * b.num_arr[0] + a.num_arr[1] * b.num_arr[1];
}
/* Vector by-element multiplication */
template <class T> gvec<T> gvec_bemult(struct gvec<T> a, struct gvec<T> b)
{
	struct gvec<T> c (a.num_arr[0], a.num_arr[1]);
	for (int i = 0; i < sizeof(c.num_arr) / sizeof(*c.num_arr); i++)
		c.num_arr[i] *= b.num_arr[i];
	return c;
}
/* Assignment method for vector */
template <class T> void gvec_assign (gvec<T> a, gvec<T> b)
{
	for (size_t i = 0; i < sizeof(a.num_arr)/sizeof(*a.num_arr); i++)
	{
		a.num_arr[i] = b.num_arr[i];
	}
}
/* Assignment method for vector with an array */
template <class T> void gvec_assign (gvec<T>* a, T b[2])
{
	a->num_arr[0] = b[0];
	a->num_arr[1] = b[1];
}

template <class T> bool gvec_eq(gvec<T> a, gvec<T> b) // Vector and vector equality
{
	if (a.num_arr[0] == b.num_arr[0] & a.num_arr[1] == b.num_arr[1]) return true; 
	else return false;
}

template <class T> gvec<T> gvec<T>::operator + (gvec<T> a) // Vector and vector additon
{
	return gvec_add(*this, a);
}
template <class T> gvec<T> gvec<T>::operator - (gvec<T> a) // Vector and vector substraction
{
	return gvec_sub(*this, a);
}
template <class T> gvec<T> gvec<T>::operator + (T a) // Vector and primitive addition {
{
	return gvec_add(*this, a);
}
template <class T> gvec<T> gvec<T>::operator - (T a) // Vector and primitive substraction
{
	return gvec_sub(*this, a);
}
template <class T> T gvec<T>::operator * (gvec<T> a) // Dot product
{
	return gvec_mult(*this, a);
}
template <class T> gvec<T> gvec<T>::operator * (T a) // Vector and primitive multiplication
{
	return gvec_mult(*this, a);
}
template <class T> bool gvec<T>::operator == (const gvec<T> a) // Vector to vector Equality
{
	return gvec_eq(*this, a);
}
template <class T> bool gvec<T>::operator == (const T a[2]) // Vector to array equality
{
	gvec<T> b (a[0], a[1]);
	return gvec_eq(*this, b);
}
template <class T> gvec<T>::gvec (T a, T b) // Constructor
{
	this->num_arr[0] = a;
	this->num_arr[1] = b;
}
template <class T> gvec<T>::gvec ()
{
}

#endif
