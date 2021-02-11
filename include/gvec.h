#ifndef  GVEC_H
#define GVEC_H
#include <vector>


template <class T>
/* 2D vector structure */
struct gvec
{
	public:
		/// Array of elements of the vector.
		T num_arr[2];
		/// Vector and vector additon.
		gvec<T> operator + (gvec<T> a);
		/// Vector and vector substraction.
		gvec<T> operator - (gvec<T> a);
		/// Vector and primitive addition.
		gvec<T> operator + (T a);
		/// Vector and primitive substraction.
		gvec<T> operator - (T a);
		/// Dot product.
		T operator * (gvec<T> a);
		/// Vector and primitive multiplication.
		gvec<T> operator * (T a);
		/// Vector to vector Equality.
		bool operator == (const gvec<T> a);
		/// Vector to array equality.
		bool operator == (const T a[2]);
		/// Constructor with defined values.
		gvec<T> (T a, T b);
		/// Null vector constructor.
		gvec<T> ();
};

/// Vector of doubles.
typedef gvec<double> dvec;
/// Vector of integers.
typedef gvec<int> ivec;


/**
 * Perform vector addition.
 * @param a 1st vector.
 * @param b 2nd vector.
 * @return Resulting addition.
 */
template <class T> gvec<T> gvec_add(struct gvec<T> a, struct gvec<T> b) {
	return gvec<T> (a.num_arr[0] + b.num_arr[0], 
			a.num_arr[1] + b.num_arr[1]);
}

/**
 * Perform vector and single number addition.
 * @param a Vector to add to.
 * @param b Adding single number.
 * @return resulting addition.
 */
template <class T> gvec<T> gvec_add(struct gvec<T> a, T b) {
	struct gvec<T> c (0, 0);
	for (int i = 0; i < sizeof(c.num_arr) / sizeof(*c.num_arr); i++)
	{
		c.num_arr[i] = a.num_arr[i] + b;
	}
	return c;
}

/**
 * Multiply vector by a single number.
 * @param a Vector to multiply.
 * @param b Number used as factor.
 * @param resulting product.
 */
template <class T> gvec<T> gvec_mult(struct gvec<T> a, T b) {
	struct gvec<T> c (a.num_arr[0], a.num_arr[1]);
	for (int i = 0; i < sizeof(c.num_arr) / sizeof(*c.num_arr); i++)
		c.num_arr[i] *= b;
	return c;
}

/**
 * Perform vector dot product.
 * @param a lhs row vector.
 * @param b rhs column vector.
 * @return Resulting dot product.
 */
template <class T> T gvec_mult(struct gvec<T> a, struct gvec<T> b) {
	return a.num_arr[0] * b.num_arr[0] + a.num_arr[1] * b.num_arr[1];
}

/**
 * Perform by-element vector product.
 * @param a 1st vector.
 * @param b 2nd vector.
 * @return Resulting product.
 */
template <class T> gvec<T> gvec_bemult(struct gvec<T> a, struct gvec<T> b) {
	struct gvec<T> c (a.num_arr[0], a.num_arr[1]);
	for (int i = 0; i < sizeof(c.num_arr) / sizeof(*c.num_arr); i++)
		c.num_arr[i] *= b.num_arr[i];
	return c;
}

/**
 * Assign value to a vector.
 * @param a vector to assign to.
 * @param b vector to copy.
 */
template <class T> void gvec_assign (gvec<T> a, gvec<T> b) {
	for (size_t i = 0; i < sizeof(a.num_arr)/sizeof(*a.num_arr); i++) {
		a.num_arr[i] = b.num_arr[i];
	}
}

/**
 * Assign array of values to a vector.
 * @param a Vector to assign to.
 * @param b Array to assign to vector.
 */
template <class T> void gvec_assign (gvec<T>* a, T b[2]) {
	a->num_arr[0] = b[0];
	a->num_arr[1] = b[1];
}

/**
 * Perform vector equality.
 * @param a 1st vector.
 * @param b 2nd vector.
 * @return Equality status.
 */
template <class T> bool gvec_eq(gvec<T> a, gvec<T> b) {
	if (a.num_arr[0] == b.num_arr[0] & a.num_arr[1] == b.num_arr[1]) return true; 
	else return false;
}

template <class T> gvec<T> gvec<T>::operator + (gvec<T> a)  {
	return gvec_add(*this, a);
}
template <class T> gvec<T> gvec<T>::operator - (gvec<T> a) {
	return gvec_add(*this, a * (-1));
}
template <class T> gvec<T> gvec<T>::operator + (T a) {
	return gvec_add(*this, a);
}
template <class T> gvec<T> gvec<T>::operator - (T a) {
	return gvec_add(*this, a * (-1));
}
template <class T> T gvec<T>::operator * (gvec<T> a) {
	return gvec_mult(*this, a);
}
template <class T> gvec<T> gvec<T>::operator * (T a) {
	return gvec_mult(*this, a);
}
template <class T> bool gvec<T>::operator == (const gvec<T> a) {
	return gvec_eq(*this, a);
}
template <class T> bool gvec<T>::operator == (const T a[2]) {
	gvec<T> b (a[0], a[1]);
	return gvec_eq(*this, b);
}
template <class T> gvec<T>::gvec (T a, T b) {
	this->num_arr[0] = a;
	this->num_arr[1] = b;
}
template <class T> gvec<T>::gvec () {
	this->num_arr[0] = 0;
	this->num_arr[1] = 0;
}

#endif
