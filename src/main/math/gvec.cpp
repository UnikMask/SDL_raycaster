#include "gvec.h"

template <class T> struct gvec<T> gvec_add(struct gvec<T> a, struct gvec<T> b)
{
	struct gvec<T> c;
	for (int i = 0; i < sizeof(c.num_arr) / sizeoff(*c.num_arr); i++)
		c.num_arr[i] = a.num_arr[i] + b.num_arr[i];
	return c;
}

template <class T> struct gvec<T> gvec_sub(struct gvec<T> a, struct gvec<T> b)
{
	struct gvec<T> c;
	for (int i = 0; i < sizeof(c.num_arr) / sizeoff(*c.num_arr); i++)
		c.num_arr[i] = a.num_arr[i] - b.num_arr[i];
	return c;
}

template <class T> struct gvec<T> gvec_add(struct gvec<T> a, T b)
{
	struct gvec<T> c;
	for (int i = 0; i < sizeof(c.num_arr) / sizeoff(*c.num_arr); i++)
		c.num_arr[i] = a.num_arr[i] + b;
	return c;
}

template <class T> struct gvec<T> gvec_sub(struct gvec<T> a, T b)
{
	struct gvec<T> c;
	for (int i = 0; i < sizeof(c.num_arr) / sizeoff(*c.num_arr); i++)
		c.num_arr[i] = a.num_arr[i] - b;
	return c;
}

template <class T> struct gvec<T> gvec_mult(struct gvec<T> a, T b)
{
	struct gvec<T> c;
	for (int i = 0; i < sizeof(c.num_arr) / sizeoff(*c.num_arr); i++)
		c.num_arr[i] = a.num_arr[i] * b;
	return c;
}

template <class T> T gvec_mult(struct gvec<T> a, struct gvec<T> b)
{
	return a.num_arr[0] * b.num_arr[0] + a.num_arr[1] * b.num_arr[1];
}

template <class T> struct gvec<T> gvec_bemult(struct gvec<T> a, struct gvec<T> b)
{
	struct gvec<T> c;
	for (int i = 0; i < sizeof(c.num_arr) / sizeoff(*c.num_arr); i++)
		c.num_arr[i] = a.num_arr[i] * b.num_arr[i];
	return c;
}

template<class T> gvec<T> gvec<T>::operator + (gvec<T> a)
{
	return gvec_add(this, a);
}
template<class T> gvec<T> gvec<T>::operator - (gvec<T> a)
{
	return gvec_sub(this, a);
}
template<class T> gvec<T> gvec<T>::operator + (T a)
{
	return gvec_add(this, a);
}
template<class T> gvec<T> gvec<T>::operator - (T a)
{
	return gvec_sub(this, a);
}
template<class T> T gvec<T>::operator * (gvec<T> a)
{
	return gvec_mult(this, a);
}
template<class T> gvec<T> gvec<T>::operator * (T a)
{
	return gvec_mult(this, a);
}
