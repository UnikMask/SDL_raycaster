#include "gmat.h"

template <class T> gmat<T>::gmat(T m00, T m01, T m10, T m11)
{
	this->num_arr = {
		{m00, m01},
		{m10, m11}
	};
}

template <class T> gmat<T>::gmat(gvec<T> row0, gvec<T> row1)
{
	this->num_arr = {row0.num_arr, row1.num_arr};
}

template <class T> struct gmat<T> gmat_add(struct gmat<T> a, struct gmat<T> b)
{
	struct gmat<T> c;
	// Loop on multiplied lengths of num_arr's rows and columns.
	for (int i = 0; i < sizeof(c.num_arr) / sizeof(c.num_arr[0]) 
			* sizeof(c.num_arr[0]) / sizeof(T); i++)
	{
		int row = i % (sizeof(c.num_arr) / sizeof(c.num_arr[0]));
		int col = i / (sizeof(c.num_arr) / sizeof(c.num_arr[0]));
		c.num_arr[row][col] = a.num_arr[row][col] + b[row][col];
	}
	return  c;
}

template <class T> struct gmat<T> gmat_sub(struct gmat<T> a, struct gmat<T> b)
{
	struct gmat<T> c;
	// Loop on multiplied lengths of num_arr's rows and columns.
	for (int i = 0; i < sizeof(c.num_arr) / sizeof(c.num_arr[0]) 
			* sizeof(c.num_arr[0]) / sizeof(T); i++)
	{
		int row = i % (sizeof(c.num_arr) / sizeof(c.num_arr[0]));
		int col = i / (sizeof(c.num_arr) / sizeof(c.num_arr[0]));
		c.num_arr[row][col] = a.num_arr[row][col] - b[row][col];
	}
	return  c;
}

template <class T> struct gmat<T> gmat_add(struct gmat<T> a, T b)
{
	struct gmat<T> c;
	// Loop on multiplied lengths of num_arr's rows and columns.
	for (int i = 0; i < sizeof(c.num_arr) / sizeof(c.num_arr[0]) 
			* sizeof(c.num_arr[0]) / sizeof(T); i++)
	{
		int row = i % (sizeof(c.num_arr) / sizeof(c.num_arr[0]));
		int col = i / (sizeof(c.num_arr) / sizeof(c.num_arr[0]));
		c.num_arr[row][col] = a.num_arr[row][col] + b;
	}
	return  c;
}

template <class T> struct gmat<T> gmat_sub(struct gmat<T> a, T b)
{
	struct gmat<T> c;
	// Loop on multiplied lengths of num_arr's rows and columns.
	for (int i = 0; i < sizeof(c.num_arr) / sizeof(c.num_arr[0]) 
			* sizeof(c.num_arr[0]) / sizeof(T); i++)
	{
		int row = i % (sizeof(c.num_arr) / sizeof(c.num_arr[0]));
		int col = i / (sizeof(c.num_arr) / sizeof(c.num_arr[0]));
		c.num_arr[row][col] = a.num_arr[row][col] - b;
	}
	return  c;
}

template <class T> struct gmat<T> gmat_mult(struct gmat<T> a, struct gmat<T> b)
{
	struct gmat<T> c;
	// Loop on multiplied lengths of num_arr's rows and columns.
	for (int i = 0; i < sizeof(c.num_arr) / sizeof(c.num_arr[0]) 
			* sizeof(c.num_arr[0]) / sizeof(T); i++)
	{
		int row = i % (sizeof(c.num_arr) / sizeof(c.num_arr[0]));
		int col = i / (sizeof(c.num_arr) / sizeof(c.num_arr[0]));

		// Initialize position on c and loop through a's row size.
		c.num_arr[row][col] = 0;
		for (int n = 0; n < sizeof(a.num_arr) / sizeof(a.num_arr[0]); n++) 
			c.num_arr[row][col] += a.num_arr[row][n] * b.num_arr[n][col];
	}
	return  c;
}

template <class T> struct gvec<T> gmat_mult(struct gvec<T> a, struct gmat<T> b)
{
	struct gvec<T> c;
	for (int i = 0; i < sizeof(c.num_arr) / sizeof(T); i++)
	{
		c.num_arr[i] = 0;
		for (int n = 0; n < sizeof(a.num_arr) / sizeof(T); n++)
			c.num_arr[i] += a.num_arr[n] * b.num_arr[n][i];
	}
	return c;
}

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

template <class T> struct gmat<T> gmat_bemult(struct gmat<T> a, struct gmat<T> b)
{
	struct gmat<T> c;
	// Loop on multiplied lengths of num_arr's rows and columns.
	for (int i = 0; i < sizeof(c.num_arr) / sizeof(c.num_arr[0]) 
			* sizeof(c.num_arr[0]) / sizeof(T); i++)
	{
		int row = i % (sizeof(c.num_arr) / sizeof(c.num_arr[0]));
		int col = i / (sizeof(c.num_arr) / sizeof(c.num_arr[0]));
		c.num_arr[row][col] = a.num_arr[row][col] * b.num_arr[row][col];
	}
	return  c;
}

template <class T> bool gmat_eq(struct gmat<T> a, struct gmat<T> b)
{
	return ( a.num_arr[0][0] == b.num_arr[0][0] && a.num_arr[0][1] == b.num_arr[0][1] &&
			 a.num_arr[1][0] == b.num_arr[1][0] && a.num_arr[1][1] == b.num_arr[1][1]);
}

template <class T> gmat<T> gmat<T>::operator + (gmat<T> a)
{
	return gmat_add(this, a);
}
template <class T> gmat<T> gmat<T>::operator - (gmat<T> a)
{
	return gmat_sub(this, a);
}
template <class T> gmat<T> gmat<T>::operator + (T a)
{
	return gmat_add(this, a);
}
template <class T> gmat<T> gmat<T>::operator - (T a)
{
	return gmat_sub(this, a);
}
template <class T> gmat<T> gmat<T>::operator * (gmat<T> a)
{
	return gmat_mult(this, a);
}
template <class T> gvec<T> gmat<T>::operator * (gvec<T> a)
{
	return gmat_mult(this, a);
}
template <class T> gmat<T> gmat<T>::operator * (T a)
{
	return gmat_mult(this, a);
}
template <class T> gvec<T> operator * (struct gvec<T> a, struct gmat<T> b)
{
	return gmat_mult(a, b);
}
template <class T> bool gmat<T>::operator == (gmat<T> a)
{
	return gmat_eq(this, a);
}
template <class T> gmat<T> gmat<T>::operator = (T a[2][2])
{
	gmat<T> ret_mat;
	ret_mat.num_arr = a;
	return ret_mat;
}
